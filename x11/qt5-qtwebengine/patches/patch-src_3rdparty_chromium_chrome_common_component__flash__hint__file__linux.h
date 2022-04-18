$NetBSD: patch-src_3rdparty_chromium_chrome_common_component__flash__hint__file__linux.h,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/chrome/common/component_flash_hint_file_linux.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/chrome/common/component_flash_hint_file_linux.h
@@ -7,7 +7,7 @@
 
 #include "build/build_config.h"
 
-#if !defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
 #error "This file only applies to the Linux component update of Flash."
 #endif  // !defined(OS_LINUX) && !defined(OS_CHROMEOS)
 
