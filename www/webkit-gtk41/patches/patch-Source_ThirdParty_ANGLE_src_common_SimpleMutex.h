$NetBSD: patch-Source_ThirdParty_ANGLE_src_common_SimpleMutex.h,v 1.1 2026/08/30 14:25:05 wiz Exp $

No futex on NetBSD.

--- Source/ThirdParty/ANGLE/src/common/SimpleMutex.h.orig	2024-11-01 23:28:13.485199177 +0000
+++ Source/ThirdParty/ANGLE/src/common/SimpleMutex.h
@@ -33,7 +33,9 @@
 //
 // There is no TSAN support for futex currently, so it is disabled in that case
 #if !defined(ANGLE_WITH_TSAN)
-#    if defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_ANDROID)
+#    if defined(ANGLE_PLATFORM_NETBSD)
+#        define ANGLE_USE_FUTEX 0
+#    elif defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_ANDROID)
 // Linux has had futexes for a very long time.  Assume support.
 #        define ANGLE_USE_FUTEX 1
 #    elif defined(ANGLE_PLATFORM_WINDOWS) && !defined(ANGLE_ENABLE_WINDOWS_UWP) && \
