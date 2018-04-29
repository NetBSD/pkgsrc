$NetBSD: patch-widget_gtk_nsClipboard.h,v 1.1 2018/04/29 13:27:08 martin Exp $

Upstream fixes for Bug 1447925 -
 Add GetClipboardText() to get text data from clipboard
 Use GetClipboardText() to get text data at nsClipboard::GetData()

--- widget/gtk/nsClipboard.h.orig	2018-04-29 12:56:52.405642009 +0000
+++ widget/gtk/nsClipboard.h
@@ -13,16 +13,18 @@
 #include "nsIBinaryOutputStream.h"
 #include <gtk/gtk.h>
 
-// Default Gtk MIME for text
-#define GTK_DEFAULT_MIME_TEXT "UTF8_STRING"
-
 class nsRetrievalContext {
 public:
+    // Get actual clipboard content (GetClipboardData/GetClipboardText)
+    // which has to be released by ReleaseClipboardData().
     virtual const char* GetClipboardData(const char* aMimeType,
                                          int32_t aWhichClipboard,
                                          uint32_t* aContentLength) = 0;
+    virtual const char* GetClipboardText(int32_t aWhichClipboard) = 0;
     virtual void ReleaseClipboardData(const char* aClipboardData) = 0;
 
+    // Get data mime types which can be obtained from clipboard.
+    // The returned array has to be released by g_free().
     virtual GdkAtom* GetTargets(int32_t aWhichClipboard,
                                 int* aTargetNum) = 0;
 
