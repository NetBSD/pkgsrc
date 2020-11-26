$NetBSD: patch-js_src_wasm_WasmBaselineCompile.cpp,v 1.1 2020/11/26 09:51:22 tnn Exp $

https://github.com/mozilla/gecko-dev/commit/71597faac0fde4f608a60dd610d0cefac4972cc3.patch

--- js/src/wasm/WasmBaselineCompile.cpp.orig	2020-11-25 22:18:17.992966827 +0000
+++ js/src/wasm/WasmBaselineCompile.cpp
@@ -654,15 +654,13 @@ class BaseRegAlloc {
 
   template <MIRType t>
   bool hasFPU() {
-    return availFPU.hasAny<RegTypeOf<t>::value>();
-  }
-
 #ifdef RABALDR_SIDEALLOC_V128
-  template <>
-  bool hasFPU<MIRType::Simd128>() {
-    MOZ_CRASH("Should not happen");
-  }
+    if constexpr (t == MIRType::Simd128)
+      MOZ_CRASH("Should not happen");
+    else
 #endif
+    return availFPU.hasAny<RegTypeOf<t>::value>();
+  }
 
   bool isAvailableGPR(Register r) { return availGPR.has(r); }
 
@@ -745,15 +743,13 @@ class BaseRegAlloc {
 
   template <MIRType t>
   FloatRegister allocFPU() {
-    return availFPU.takeAny<RegTypeOf<t>::value>();
-  }
-
 #ifdef RABALDR_SIDEALLOC_V128
-  template <>
-  FloatRegister allocFPU<MIRType::Simd128>() {
-    MOZ_CRASH("Should not happen");
-  }
+    if constexpr (t == MIRType::Simd128)
+      MOZ_CRASH("Should not happen");
+    else
 #endif
+    return availFPU.takeAny<RegTypeOf<t>::value>();
+  }
 
   void freeGPR(Register r) { availGPR.add(r); }
 
