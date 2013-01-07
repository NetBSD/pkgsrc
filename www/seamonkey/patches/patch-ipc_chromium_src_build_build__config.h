$NetBSD: patch-ipc_chromium_src_build_build__config.h,v 1.9 2013/01/07 21:55:30 ryoon Exp $

--- mozilla/ipc/chromium/src/build/build_config.h.orig	2012-11-18 10:19:38.000000000 +0000
+++ mozilla/ipc/chromium/src/build/build_config.h
@@ -19,6 +19,12 @@
 #define OS_MACOSX 1
 #elif defined(__linux__) || defined(ANDROID)
 #define OS_LINUX 1
+#elif defined(__DragonFly__)
+#define OS_DRAGONFLY 1
+#elif defined(__FreeBSD__)
+#define OS_FREEBSD 1
+#elif defined(__NetBSD__)
+#define OS_NETBSD 1
 #elif defined(__OpenBSD__)
 #define OS_OPENBSD 1
 #elif defined(_WIN32)
@@ -27,9 +33,16 @@
 #error Please add support for your platform in build/build_config.h
 #endif
 
+// For access to standard BSD features, use OS_BSD instead of a
+// more specific macro.
+#if defined(OS_DRAGONFLY) || defined(OS_FREEBSD)	\
+  || defined(OS_NETBSD) || defined(OS_OPENBSD)
+#define OS_BSD 1
+#endif
+
 // For access to standard POSIX features, use OS_POSIX instead of a more
 // specific macro.
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 #define OS_POSIX 1
 #endif
 
