$NetBSD: patch-js_src_wasm_WasmBCRegDefs.h,v 1.1 2021/10/25 17:44:49 tnn Exp $

https://hg.mozilla.org/integration/autoland/rev/eac402936496

--- js/src/wasm/WasmBCRegDefs.h.orig	2021-09-27 23:17:27.000000000 +0000
+++ js/src/wasm/WasmBCRegDefs.h
@@ -379,7 +379,10 @@ struct SpecificRegs {
   SpecificRegs() : abiReturnRegI64(ReturnReg64) {}
 };
 #elif defined(JS_CODEGEN_ARM64)
-struct SpecificRegs {};
+struct SpecificRegs {
+  // Required by gcc.
+  SpecificRegs() {}
+};
 #elif defined(JS_CODEGEN_MIPS32)
 struct SpecificRegs {
   RegI64 abiReturnRegI64;
@@ -387,7 +390,10 @@ struct SpecificRegs {
   SpecificRegs() : abiReturnRegI64(ReturnReg64) {}
 };
 #elif defined(JS_CODEGEN_MIPS64)
-struct SpecificRegs {};
+struct SpecificRegs {
+  // Required by gcc.
+  SpecificRegs() {}
+};
 #else
 struct SpecificRegs {
 #  ifndef JS_64BIT
