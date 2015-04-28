$NetBSD: patch-js_src_jit_arm_BaselineIC-arm.cpp,v 1.1 2015/04/28 12:06:34 joerg Exp $

--- js/src/jit/arm/BaselineIC-arm.cpp.orig	2015-04-20 23:58:14.000000000 +0000
+++ js/src/jit/arm/BaselineIC-arm.cpp
@@ -71,7 +71,7 @@ ICCompare_Double::Compiler::generateStub
 // ICBinaryArith_Int32
 
 extern "C" {
-    extern int64_t __aeabi_idivmod(int,int);
+    extern int64_t __aeabi_idivmod(int,int) MOZ_EXPORT;
 }
 
 bool
