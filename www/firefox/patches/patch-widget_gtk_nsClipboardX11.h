$NetBSD: patch-widget_gtk_nsClipboardX11.h,v 1.1 2018/04/29 13:27:08 martin Exp $

Upstream fixes for Bug 1447925 -
 Add GetClipboardText() to get text data from clipboard
 Use GetClipboardText() to get text data at nsClipboard::GetData()

--- widget/gtk/nsClipboardX11.h.orig	2018-04-29 12:56:52.405751519 +0000
+++ widget/gtk/nsClipboardX11.h
@@ -11,6 +11,12 @@
 #include "nsIClipboard.h"
 #include <gtk/gtk.h>
 
+enum ClipboardDataType {
+    CLIPBOARD_DATA,
+    CLIPBOARD_TEXT,
+    CLIPBOARD_TARGETS
+};
+
 class nsRetrievalContextX11 : public nsRetrievalContext
 {
 public:
@@ -19,48 +25,59 @@ public:
     virtual const char* GetClipboardData(const char* aMimeType,
                                          int32_t aWhichClipboard,
                                          uint32_t* aContentLength) override;
+    virtual const char* GetClipboardText(int32_t aWhichClipboard) override;
     virtual void ReleaseClipboardData(const char* aClipboardData) override;
 
     virtual GdkAtom* GetTargets(int32_t aWhichClipboard,
                                 int* aTargetNums) override;
 
-    // Call this when data has been retrieved.
-    void Complete(GtkSelectionData* aData, int aDataRequestNumber);
+    // Call this when data or text has been retrieved.
+    void Complete(ClipboardDataType aDataType,
+                  const void* aData,
+                  int aDataRequestNumber);
 
     nsRetrievalContextX11();
     virtual ~nsRetrievalContextX11() override;
 
 private:
-    GtkSelectionData* WaitForContents(GtkClipboard *clipboard,
-                                      const char *aMimeType);
+    bool WaitForClipboardData(ClipboardDataType aDataType,
+                              GtkClipboard *clipboard,
+                              const char *aMimeType = nullptr);
+
     /**
      * Spins X event loop until timing out or being completed. Returns
      * null if we time out, otherwise returns the completed data (passing
      * ownership to caller).
      */
-    void *Wait();
+    bool WaitForX11Content();
 
-    State mState;
-    void* mData;
-    int   mClipboardRequestNumber;
+    State     mState;
+    int       mClipboardRequestNumber;
+    void*     mClipboardData;
+    uint32_t  mClipboardDataLength;
+    GdkAtom   mTargetMIMEType;
 };
 
 class ClipboardRequestHandler
 {
 public:
-    ClipboardRequestHandler(nsRetrievalContextX11 *aContext, int aDataRequestNumber)
+    ClipboardRequestHandler(nsRetrievalContextX11 *aContext,
+                            ClipboardDataType aDataType,
+                            int aDataRequestNumber)
       : mContext(aContext)
       , mDataRequestNumber(aDataRequestNumber)
+      , mDataType(aDataType)
       {}
 
-    void  Complete(GtkSelectionData* aData)
+    void Complete(const void *aData)
     {
-      mContext->Complete(aData, mDataRequestNumber);
+      mContext->Complete(mDataType, aData, mDataRequestNumber);
     }
 
 private:
     nsRetrievalContextX11 *mContext;
     int                    mDataRequestNumber;
+    ClipboardDataType      mDataType;
 };
 
 #endif /* __nsClipboardX11_h_ */
