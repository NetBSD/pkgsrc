$NetBSD: patch-js_src_jit_arm_Architecture-arm.cpp,v 1.1 2015/04/28 12:06:34 joerg Exp $

--- js/src/jit/arm/Architecture-arm.cpp.orig	2015-04-10 17:17:56.000000000 +0000
+++ js/src/jit/arm/Architecture-arm.cpp
@@ -17,7 +17,7 @@
 
 #define HWCAP_USE_HARDFP_ABI (1 << 28)
 
-#if !(defined(ANDROID) || defined(MOZ_B2G)) && !defined(JS_ARM_SIMULATOR)
+#if defined(__linux__) && !(defined(ANDROID) || defined(MOZ_B2G)) && !defined(JS_ARM_SIMULATOR)
 #define HWCAP_ARMv7 (1 << 29)
 #include <asm/hwcap.h>
 #else
@@ -212,6 +212,9 @@ uint32_t GetARMFlags()
 
     isSet = true;
     return flags;
+#elif defined(__NetBSD__)
+    /* XXX */
+    return 0;
 #endif
 
     return 0;
