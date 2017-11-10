$NetBSD: patch-mozilla_js_src_jit_arm_Architecture-arm.cpp,v 1.5 2017/11/10 22:45:27 ryoon Exp $

--- mozilla/js/src/jit/arm/Architecture-arm.cpp.orig	2017-10-16 07:18:17.000000000 +0000
+++ mozilla/js/src/jit/arm/Architecture-arm.cpp
@@ -16,7 +16,7 @@
 #include "jit/arm/Assembler-arm.h"
 #include "jit/RegisterSets.h"
 
-#if !defined(__linux__) || defined(ANDROID) || defined(JS_SIMULATOR_ARM)
+#if !defined(__linux__) || defined(ANDROID) || defined(JS_SIMULATOR_ARM) || defined(__NetBSD__)
 // The Android NDK and B2G do not include the hwcap.h kernel header, and it is not
 // defined when building the simulator, so inline the header defines we need.
 # define HWCAP_VFP        (1 << 6)
