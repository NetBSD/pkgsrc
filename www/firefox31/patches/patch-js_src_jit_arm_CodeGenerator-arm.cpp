$NetBSD: patch-js_src_jit_arm_CodeGenerator-arm.cpp,v 1.1 2015/04/28 12:06:34 joerg Exp $

--- js/src/jit/arm/CodeGenerator-arm.cpp.orig	2015-04-20 23:29:04.000000000 +0000
+++ js/src/jit/arm/CodeGenerator-arm.cpp
@@ -619,8 +619,8 @@ CodeGeneratorARM::visitDivI(LDivI *ins)
 }
 
 extern "C" {
-    extern int64_t __aeabi_idivmod(int,int);
-    extern int64_t __aeabi_uidivmod(int,int);
+    extern int64_t __aeabi_idivmod(int,int) MOZ_EXPORT;
+    extern int64_t __aeabi_uidivmod(int,int) MOZ_EXPORT;
 }
 
 bool
