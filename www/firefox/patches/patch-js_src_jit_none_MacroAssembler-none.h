$NetBSD: patch-js_src_jit_none_MacroAssembler-none.h,v 1.3 2017/08/15 01:24:47 ryoon Exp $

* Support bigendian architectures

--- js/src/jit/none/MacroAssembler-none.h.orig	2017-07-31 16:20:48.000000000 +0000
+++ js/src/jit/none/MacroAssembler-none.h
@@ -48,7 +48,7 @@ static constexpr Register WasmIonExitReg
 
 static constexpr Register WasmIonExitRegReturnData { Registers::invalid_reg };
 static constexpr Register WasmIonExitRegReturnType { Registers::invalid_reg };
-static constexpr Register WasmIonExitTlsReg = { Registers::invalid_reg };
+static constexpr Register WasmIonExitTlsReg { Registers::invalid_reg };
 static constexpr Register WasmIonExitRegD0 { Registers::invalid_reg };
 static constexpr Register WasmIonExitRegD1 { Registers::invalid_reg };
 static constexpr Register WasmIonExitRegD2 { Registers::invalid_reg };
@@ -153,6 +153,8 @@ class Assembler : public AssemblerShared
 
     static uintptr_t GetPointer(uint8_t*) { MOZ_CRASH(); }
 
+    static bool HasRoundInstruction(RoundingMode) { return false; }
+
     void verifyHeapAccessDisassembly(uint32_t begin, uint32_t end,
                                      const Disassembler::HeapAccess& heapAccess)
     {
@@ -196,9 +198,7 @@ class MacroAssemblerNone : public Assemb
     static bool SupportsSimd() { return false; }
     static bool SupportsUnalignedAccesses() { return false; }
 
-    static bool HasRoundInstruction(RoundingMode) { return false; }
-
-    void executableCopy(void*, bool) { MOZ_CRASH(); }
+    void executableCopy(void*, bool = true) { MOZ_CRASH(); }
     void copyJumpRelocationTable(uint8_t*) { MOZ_CRASH(); }
     void copyDataRelocationTable(uint8_t*) { MOZ_CRASH(); }
     void copyPreBarrierTable(uint8_t*) { MOZ_CRASH(); }
