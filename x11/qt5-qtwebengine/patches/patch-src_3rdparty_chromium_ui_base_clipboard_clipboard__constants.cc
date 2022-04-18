$NetBSD: patch-src_3rdparty_chromium_ui_base_clipboard_clipboard__constants.cc,v 1.1 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/ui/base/clipboard/clipboard_constants.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/ui/base/clipboard/clipboard_constants.cc
@@ -16,7 +16,7 @@ const char kMimeTypeSvg[] = "image/svg+x
 const char kMimeTypeRTF[] = "text/rtf";
 const char kMimeTypePNG[] = "image/png";
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
 const char kMimeTypeLinuxUtf8String[] = "UTF8_STRING";
 const char kMimeTypeLinuxString[] = "STRING";
 const char kMimeTypeLinuxText[] = "TEXT";
