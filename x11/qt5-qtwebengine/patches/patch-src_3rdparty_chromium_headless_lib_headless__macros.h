$NetBSD: patch-src_3rdparty_chromium_headless_lib_headless__macros.h,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/headless/lib/headless_macros.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/headless/lib/headless_macros.h
@@ -7,7 +7,7 @@
 
 #include "build/build_config.h"
 
-#if defined(OS_POSIX) && !defined(OS_MAC)
+#if defined(OS_POSIX) && !defined(OS_MAC) && !defined(OS_BSD)
 #define HEADLESS_USE_BREAKPAD
 #endif  // defined(OS_POSIX) && !defined(OS_MAC)
 
