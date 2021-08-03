$NetBSD: patch-src_3rdparty_chromium_headless_lib_headless__macros.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/headless/lib/headless_macros.h.orig	2020-07-08 21:40:44.000000000 +0000
+++ src/3rdparty/chromium/headless/lib/headless_macros.h
@@ -7,7 +7,7 @@
 
 #include "build/build_config.h"
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 #define HEADLESS_USE_BREAKPAD
 #endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
 
