$NetBSD: patch-widget_gtk_nsClipboard.cpp,v 1.1 2018/04/29 13:27:08 martin Exp $

Upstream fixes for Bug 1447925 -
 Add GetClipboardText() to get text data from clipboard
 Use GetClipboardText() to get text data at nsClipboard::GetData()

--- widget/gtk/nsClipboard.cpp.orig	2018-04-29 12:56:52.405590187 +0000
+++ widget/gtk/nsClipboard.cpp
@@ -301,11 +301,8 @@ nsClipboard::GetData(nsITransferable *aT
         // Special case text/unicode since we can convert any
         // string into text/unicode
         if (flavorStr.EqualsLiteral(kUnicodeMime)) {
-            uint32_t    clipboardDataLength;
             const char* clipboardData =
-                mContext->GetClipboardData(GTK_DEFAULT_MIME_TEXT,
-                                           aWhichClipboard,
-                                           &clipboardDataLength);
+                mContext->GetClipboardText(aWhichClipboard);
             if (!clipboardData) {
                 // If the type was text/unicode and we couldn't get
                 // text off the clipboard, run the next loop
@@ -314,7 +311,7 @@ nsClipboard::GetData(nsITransferable *aT
             }
 
             // Convert utf-8 into our unicode format.
-            NS_ConvertUTF8toUTF16 ucs2string(clipboardData, clipboardDataLength);
+            NS_ConvertUTF8toUTF16 ucs2string(clipboardData);
             const char* unicodeData = (const char *)ToNewUnicode(ucs2string);
             uint32_t unicodeDataLength = ucs2string.Length() * 2;
             SetTransferableData(aTransferable, flavorStr,
