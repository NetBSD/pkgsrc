$NetBSD: patch-js_src_jit_arm64_vixl_Registers-vixl.h,v 1.1 2026/08/27 01:23:16 gutteridge Exp $

--- js/src/jit/arm64/vixl/Registers-vixl.h.orig	2026-07-09 17:58:16.713975290 +0000
+++ js/src/jit/arm64/vixl/Registers-vixl.h
@@ -188,13 +188,13 @@ class CPURegister {
   bool IsRegister() const { return GetType() == kRegister; }
   bool IsVRegister() const { return GetType() == kVRegister; }
   bool IsZRegister() const { return GetType() == kZRegister; }
-  bool IsPRegister() const { return GetType() == kPRegister; }
+  constexpr bool IsPRegister() const { return GetType() == kPRegister; }
 
   bool IsNone() const { return GetType() == kNoRegister; }
 
   // `GetType() == kNoRegister` implies IsNone(), and vice-versa.
   // `GetType() == k<Foo>Register` implies Is<Foo>Register(), and vice-versa.
-  RegisterType GetType() const {
+  constexpr RegisterType GetType() const {
     switch (bank_) {
       case kNoRegisterBank:
         return kNoRegister;
