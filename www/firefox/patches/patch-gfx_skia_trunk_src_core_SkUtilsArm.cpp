$NetBSD: patch-gfx_skia_trunk_src_core_SkUtilsArm.cpp,v 1.1 2015/10/16 12:59:36 jmcneill Exp $

--- gfx/skia/trunk/src/core/SkUtilsArm.cpp.orig	2015-09-29 21:44:49.000000000 +0000
+++ gfx/skia/trunk/src/core/SkUtilsArm.cpp
@@ -47,6 +47,11 @@
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
