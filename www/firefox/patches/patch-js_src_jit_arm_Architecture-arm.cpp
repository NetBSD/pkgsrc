$NetBSD: patch-js_src_jit_arm_Architecture-arm.cpp,v 1.1 2014/11/26 14:56:28 ryoon Exp $

* NetBSD has no asm/hwcap.h (Linux's header file).

--- js/src/jit/arm/Architecture-arm.cpp.orig	2014-11-13 22:50:01.000000000 +0000
+++ js/src/jit/arm/Architecture-arm.cpp
@@ -18,7 +18,7 @@
 
 #define HWCAP_USE_HARDFP_ABI (1 << 27)
 
-#if !(defined(ANDROID) || defined(MOZ_B2G)) && !defined(JS_ARM_SIMULATOR)
+#if !(defined(ANDROID) || defined(MOZ_B2G) || defined(__NetBSD__))) && !defined(JS_ARM_SIMULATOR)
 #define HWCAP_ARMv7 (1 << 28)
 #include <asm/hwcap.h>
 #else
