$NetBSD: patch-src_3rdparty_chromium_ui_base_clipboard_clipboard__constants.h,v 1.1 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/ui/base/clipboard/clipboard_constants.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/ui/base/clipboard/clipboard_constants.h
@@ -37,7 +37,7 @@ COMPONENT_EXPORT(UI_BASE_CLIPBOARD_TYPES
 COMPONENT_EXPORT(UI_BASE_CLIPBOARD_TYPES) extern const char kMimeTypePNG[];
 
 // Linux-specific MIME type constants (also used in Fuchsia).
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
 COMPONENT_EXPORT(UI_BASE_CLIPBOARD_TYPES)
 extern const char kMimeTypeLinuxUtf8String[];
 COMPONENT_EXPORT(UI_BASE_CLIPBOARD_TYPES)
