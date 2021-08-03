$NetBSD: patch-src_3rdparty_chromium_chrome_renderer_pepper_pepper__flash__font__file__host.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/chrome/renderer/pepper/pepper_flash_font_file_host.h.orig	2020-07-08 21:40:37.000000000 +0000
+++ src/3rdparty/chromium/chrome/renderer/pepper/pepper_flash_font_file_host.h
@@ -14,7 +14,7 @@
 #include "ppapi/c/private/pp_private_font_charset.h"
 #include "ppapi/host/resource_host.h"
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/files/file.h"
 #elif defined(OS_WIN)
 #include "third_party/skia/include/core/SkRefCnt.h"
@@ -50,7 +50,7 @@ class PepperFlashFontFileHost : public p
                          uint32_t table);
   bool GetFontData(uint32_t table, void* buffer, size_t* length);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   base::File font_file_;
 #elif defined(OS_WIN)
   sk_sp<SkTypeface> typeface_;
