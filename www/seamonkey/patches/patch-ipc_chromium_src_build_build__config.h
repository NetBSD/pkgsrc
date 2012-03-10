$NetBSD: patch-ipc_chromium_src_build_build__config.h,v 1.3 2012/03/10 03:26:05 ryoon Exp $

--- mozilla/ipc/chromium/src/build/build_config.h.orig	2012-02-16 14:09:02.000000000 +0000
+++ mozilla/ipc/chromium/src/build/build_config.h
@@ -19,6 +19,10 @@
 #define OS_MACOSX 1
 #elif defined(__linux__) || defined(ANDROID)
 #define OS_LINUX 1
+#elif defined(__NetBSD__)
+#define OS_NETBSD 1
+#elif defined(__DragonFly__)
+#define OS_DRAGONFLY 1
 #elif defined(__OpenBSD__)
 #define OS_OPENBSD 1
 #elif defined(_WIN32)
@@ -29,7 +33,7 @@
 
 // For access to standard POSIX features, use OS_POSIX instead of a more
 // specific macro.
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 #define OS_POSIX 1
 #endif
 
