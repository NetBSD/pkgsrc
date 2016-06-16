$NetBSD: patch-gfx_skia_skia_src_core_SkUtilsArm.cpp,v 1.3 2016/06/16 12:08:21 ryoon Exp $

* Support NetBSD

--- gfx/skia/skia/src/core/SkUtilsArm.cpp.orig	2016-04-15 16:57:41.000000000 +0000
+++ gfx/skia/skia/src/core/SkUtilsArm.cpp
@@ -16,6 +16,10 @@
 #include <string.h>
 #include <pthread.h>
 
+#if defined(__NetBSD__)
+#include <sys/sysctl.h>
+#endif
+
 #if defined(SK_BUILD_FOR_ANDROID)
 #  ifdef MOZ_SKIA
 #    include "mozilla/arm.h"
@@ -24,6 +28,11 @@
 #  endif
 #endif
 
+#if !defined(TEMP_FAILURE_RETRY)
+   // TEMP_FAILURE_RETRY is glibc specific
+#  define TEMP_FAILURE_RETRY
+#endif
+
 // A function used to determine at runtime if the target CPU supports
 // the ARM NEON instruction set. This implementation is Linux-specific.
 static bool sk_cpu_arm_check_neon(void) {
