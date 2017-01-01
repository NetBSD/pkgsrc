$NetBSD: patch-mozilla_gfx_skia_skia_src_core_SkUtilsArm.cpp,v 1.2 2017/01/01 16:14:07 ryoon Exp $

--- mozilla/gfx/skia/skia/src/core/SkUtilsArm.cpp.orig	2016-12-14 02:07:14.000000000 +0000
+++ mozilla/gfx/skia/skia/src/core/SkUtilsArm.cpp
@@ -15,6 +15,10 @@
 #include <string.h>
 #include <pthread.h>
 
+#if defined(__NetBSD__)
+#include <sys/sysctl.h>
+#endif
+
 #if defined(SK_BUILD_FOR_ANDROID)
 #  ifdef MOZ_SKIA
 #    include "mozilla/arm.h"
@@ -23,6 +27,11 @@
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
