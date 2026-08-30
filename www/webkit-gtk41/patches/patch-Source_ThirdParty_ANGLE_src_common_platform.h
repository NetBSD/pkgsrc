$NetBSD: patch-Source_ThirdParty_ANGLE_src_common_platform.h,v 1.1 2026/08/30 14:25:05 wiz Exp $

Add NetBSD specific define for feature tests in ANGLE.

--- Source/ThirdParty/ANGLE/src/common/platform.h.orig	2024-11-02 07:55:47.527468498 +0000
+++ Source/ThirdParty/ANGLE/src/common/platform.h
@@ -26,7 +26,10 @@
 #elif defined(__linux__) || defined(EMSCRIPTEN)
 #    define ANGLE_PLATFORM_LINUX 1
 #    define ANGLE_PLATFORM_POSIX 1
-#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) ||              \
+#elif defined(__NetBSD__)
+#    define ANGLE_PLATFORM_NETBSD 1
+#    define ANGLE_PLATFORM_POSIX 1
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) ||                                     \
     defined(__DragonFly__) || defined(__sun) || defined(__GLIBC__) || defined(__GNU__) || \
     defined(__QNX__) || defined(__Fuchsia__) || defined(__HAIKU__)
 #    define ANGLE_PLATFORM_POSIX 1
