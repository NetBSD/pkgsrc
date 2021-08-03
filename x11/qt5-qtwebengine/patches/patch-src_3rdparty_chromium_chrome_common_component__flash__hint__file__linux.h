$NetBSD: patch-src_3rdparty_chromium_chrome_common_component__flash__hint__file__linux.h,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/chrome/common/component_flash_hint_file_linux.h.orig	2020-07-24 02:37:49.000000000 +0000
+++ src/3rdparty/chromium/chrome/common/component_flash_hint_file_linux.h
@@ -7,7 +7,7 @@
 
 #include "build/build_config.h"
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
 #error "This file only applies to the Linux component update of Flash."
 #endif  // !defined(OS_LINUX)
 
