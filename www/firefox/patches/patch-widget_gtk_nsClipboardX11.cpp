$NetBSD: patch-widget_gtk_nsClipboardX11.cpp,v 1.1 2018/04/29 13:27:08 martin Exp $

Upstream fixes for Bug 1447925 -
 Add GetClipboardText() to get text data from clipboard
 Use GetClipboardText() to get text data at nsClipboard::GetData()

--- widget/gtk/nsClipboardX11.cpp.orig	2018-04-29 12:56:52.405706053 +0000
+++ widget/gtk/nsClipboardX11.cpp
@@ -62,8 +62,10 @@ selection_request_filter(GdkXEvent *gdk_
 
 nsRetrievalContextX11::nsRetrievalContextX11()
   : mState(INITIAL)
-  , mData(nullptr)
   , mClipboardRequestNumber(0)
+  , mClipboardData(nullptr)
+  , mClipboardDataLength(0)
+  , mTargetMIMEType(gdk_atom_intern("TARGETS", FALSE))
 {
     // A custom event filter to workaround attempting to dereference a null
     // selection requestor in GTK3 versions before 3.11.3. See bug 1178799.
@@ -139,13 +141,11 @@ checkEventProc(Display *display, XEvent 
     return False;
 }
 
-void *
-nsRetrievalContextX11::Wait()
+bool
+nsRetrievalContextX11::WaitForX11Content()
 {
     if (mState == COMPLETED) { // the request completed synchronously
-        void *data = mData;
-        mData = nullptr;
-        return data;
+        return true;
     }
 
     GdkDisplay *gdkDisplay = gdk_display_get_default();
@@ -181,9 +181,7 @@ nsRetrievalContextX11::Wait()
                     DispatchPropertyNotifyEvent(context.cbWidget, &xevent);
 
                 if (mState == COMPLETED) {
-                    void *data = mData;
-                    mData = nullptr;
-                    return data;
+                    return true;
                 }
             }
 
@@ -200,11 +198,12 @@ nsRetrievalContextX11::Wait()
     printf("exceeded clipboard timeout\n");
 #endif
     mState = TIMED_OUT;
-    return nullptr;
+    return false;
 }
 
 // Call this when data has been retrieved.
-void nsRetrievalContextX11::Complete(GtkSelectionData* aData,
+void nsRetrievalContextX11::Complete(ClipboardDataType aDataType,
+                                     const void* aData,
                                      int aDataRequestNumber)
 {
   if (mClipboardRequestNumber != aDataRequestNumber) {
@@ -214,8 +213,54 @@ void nsRetrievalContextX11::Complete(Gtk
 
   if (mState == INITIAL) {
       mState = COMPLETED;
-      mData = gtk_selection_data_get_length(aData) >= 0 ?
-              gtk_selection_data_copy(aData) : nullptr;
+
+      MOZ_ASSERT(mClipboardData == nullptr &&
+                 mClipboardDataLength == 0,
+                 "We're leaking clipboard data!");
+
+      switch (aDataType) {
+      case CLIPBOARD_TEXT:
+          {
+              const char* text = static_cast<const char*>(aData);
+              if (text) {
+                  mClipboardDataLength = sizeof(char) * (strlen(text) + 1);
+                  mClipboardData = moz_xmalloc(mClipboardDataLength);
+                  memcpy(mClipboardData, text, mClipboardDataLength);
+              }
+          }
+          break;
+      case CLIPBOARD_TARGETS:
+          {
+              const GtkSelectionData *selection =
+                  static_cast<const GtkSelectionData *>(aData);
+
+              gint n_targets = 0;
+              GdkAtom *targets = nullptr;
+
+              if (!gtk_selection_data_get_targets(selection, &targets, &n_targets) ||
+                  !n_targets) {
+                  return;
+              }
+
+              mClipboardData = targets;
+              mClipboardDataLength = n_targets;
+          }
+          break;
+      case CLIPBOARD_DATA:
+          {
+              const GtkSelectionData *selection =
+                  static_cast<const GtkSelectionData *>(aData);
+
+              gint dataLength = gtk_selection_data_get_length(selection);
+              if (dataLength > 0) {
+                  mClipboardDataLength = dataLength;
+                  mClipboardData = moz_xmalloc(dataLength);
+                  memcpy(mClipboardData, gtk_selection_data_get_data(selection),
+                         dataLength);
+              }
+          }
+          break;
+      }
   } else {
       // Already timed out
       MOZ_ASSERT(mState == TIMED_OUT);
@@ -233,12 +278,24 @@ clipboard_contents_received(GtkClipboard
     delete handler;
 }
 
-GtkSelectionData*
-nsRetrievalContextX11::WaitForContents(GtkClipboard *clipboard,
-                                       const char *aMimeType)
+static void
+clipboard_text_received(GtkClipboard     *clipboard,
+                        const gchar      *text,
+                        gpointer          data)
+{
+    ClipboardRequestHandler *handler =
+        static_cast<ClipboardRequestHandler*>(data);
+    handler->Complete(text);
+    delete handler;
+}
+
+bool
+nsRetrievalContextX11::WaitForClipboardData(ClipboardDataType aDataType,
+                                            GtkClipboard *clipboard,
+                                            const char *aMimeType)
 {
     mState = INITIAL;
-    NS_ASSERTION(!mData, "Leaking clipboard content!");
+    NS_ASSERTION(!mClipboardData, "Leaking clipboard content!");
 
     // Call ClipboardRequestHandler() with unique clipboard request number.
     // The request number pairs gtk_clipboard_request_contents() data request
@@ -246,39 +303,45 @@ nsRetrievalContextX11::WaitForContents(G
     // is provided by Gtk.
     mClipboardRequestNumber++;
     ClipboardRequestHandler* handler =
-        new ClipboardRequestHandler(this, mClipboardRequestNumber);
+        new ClipboardRequestHandler(this, aDataType, mClipboardRequestNumber);
+
+    switch (aDataType) {
+    case CLIPBOARD_DATA:
+        gtk_clipboard_request_contents(clipboard,
+            gdk_atom_intern(aMimeType, FALSE), clipboard_contents_received,
+            handler);
+        break;
+    case CLIPBOARD_TEXT:
+        gtk_clipboard_request_text(clipboard, clipboard_text_received,
+            handler);
+        break;
+    case CLIPBOARD_TARGETS:
+        gtk_clipboard_request_contents(clipboard,
+            mTargetMIMEType, clipboard_contents_received,
+            handler);
+        break;
+    }
 
-    gtk_clipboard_request_contents(clipboard,
-                                   gdk_atom_intern(aMimeType, FALSE),
-                                   clipboard_contents_received,
-                                   handler);
-    return static_cast<GtkSelectionData*>(Wait());
+    return WaitForX11Content();
 }
 
 GdkAtom*
 nsRetrievalContextX11::GetTargets(int32_t aWhichClipboard, int* aTargetNums)
 {
-  *aTargetNums = 0;
-
-  GtkClipboard *clipboard =
-      gtk_clipboard_get(GetSelectionAtom(aWhichClipboard));
-
-  GtkSelectionData *selection_data = WaitForContents(clipboard, "TARGETS");
-  if (!selection_data)
-      return nullptr;
+    GtkClipboard *clipboard =
+        gtk_clipboard_get(GetSelectionAtom(aWhichClipboard));
 
-  gint n_targets = 0;
-  GdkAtom *targets = nullptr;
+    if (!WaitForClipboardData(CLIPBOARD_TARGETS, clipboard))
+        return nullptr;
 
-  if (!gtk_selection_data_get_targets(selection_data, &targets, &n_targets) ||
-      !n_targets) {
-      return nullptr;
-  }
+    *aTargetNums = mClipboardDataLength;
+    GdkAtom* targets = static_cast<GdkAtom*>(mClipboardData);
 
-  gtk_selection_data_free(selection_data);
+    // We don't hold the target list internally but we transfer the ownership.
+    mClipboardData = nullptr;
+    mClipboardDataLength = 0;
 
-  *aTargetNums = n_targets;
-  return targets;
+    return targets;
 }
 
 const char*
@@ -289,25 +352,31 @@ nsRetrievalContextX11::GetClipboardData(
     GtkClipboard *clipboard;
     clipboard = gtk_clipboard_get(GetSelectionAtom(aWhichClipboard));
 
-    GtkSelectionData *selectionData = WaitForContents(clipboard, aMimeType);
-    if (!selectionData)
+    if (!WaitForClipboardData(CLIPBOARD_DATA, clipboard, aMimeType))
         return nullptr;
 
-    char* clipboardData = nullptr;
-    int contentLength = gtk_selection_data_get_length(selectionData);
-    if (contentLength > 0) {
-        clipboardData = reinterpret_cast<char*>(
-            moz_xmalloc(sizeof(char)*contentLength));
-        memcpy(clipboardData, gtk_selection_data_get_data(selectionData),
-            sizeof(char)*contentLength);
-    }
-    gtk_selection_data_free(selectionData);
+    *aContentLength = mClipboardDataLength;
+    return static_cast<const char*>(mClipboardData);
+}
+
+const char*
+nsRetrievalContextX11::GetClipboardText(int32_t aWhichClipboard)
+{
+    GtkClipboard *clipboard;
+    clipboard = gtk_clipboard_get(GetSelectionAtom(aWhichClipboard));
 
-    *aContentLength = contentLength;
-    return (const char*)clipboardData;
+    if (!WaitForClipboardData(CLIPBOARD_TEXT, clipboard))
+        return nullptr;
+
+    return static_cast<const char*>(mClipboardData);
 }
 
 void nsRetrievalContextX11::ReleaseClipboardData(const char* aClipboardData)
 {
-    free((void *)aClipboardData);
+    NS_ASSERTION(aClipboardData == mClipboardData,
+        "Releasing unknown clipboard data!");
+    free((void*)aClipboardData);
+
+    mClipboardData = nullptr;
+    mClipboardDataLength = 0;
 }
