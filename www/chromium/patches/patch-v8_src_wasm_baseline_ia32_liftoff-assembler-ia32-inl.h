$NetBSD: patch-v8_src_wasm_baseline_ia32_liftoff-assembler-ia32-inl.h,v 1.1 2025/02/06 09:58:37 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/wasm/baseline/ia32/liftoff-assembler-ia32-inl.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ v8/src/wasm/baseline/ia32/liftoff-assembler-ia32-inl.h
@@ -579,7 +579,7 @@ void LiftoffAssembler::StoreTaggedPointe
 }
 
 void LiftoffAssembler::Load(LiftoffRegister dst, Register src_addr,
-                            Register offset_reg, uint32_t offset_imm,
+                            Register offset_reg, uintptr_t offset_imm,
                             LoadType type, uint32_t* protected_load_pc,
                             bool /* is_load_mem */, bool /* i64_offset */,
                             bool needs_shift) {
@@ -659,7 +659,7 @@ void LiftoffAssembler::Load(LiftoffRegis
 }
 
 void LiftoffAssembler::Store(Register dst_addr, Register offset_reg,
-                             uint32_t offset_imm, LiftoffRegister src,
+                             uintptr_t offset_imm, LiftoffRegister src,
                              StoreType type, LiftoffRegList pinned,
                              uint32_t* protected_store_pc,
                              bool /* is_store_mem */, bool /* i64_offset */) {
@@ -738,7 +738,7 @@ void LiftoffAssembler::Store(Register ds
 }
 
 void LiftoffAssembler::AtomicLoad(LiftoffRegister dst, Register src_addr,
-                                  Register offset_reg, uint32_t offset_imm,
+                                  Register offset_reg, uintptr_t offset_imm,
                                   LoadType type, LiftoffRegList /* pinned */,
                                   bool /* i64_offset */) {
   if (type.value() != LoadType::kI64Load) {
@@ -756,7 +756,7 @@ void LiftoffAssembler::AtomicLoad(Liftof
 }
 
 void LiftoffAssembler::AtomicStore(Register dst_addr, Register offset_reg,
-                                   uint32_t offset_imm, LiftoffRegister src,
+                                   uintptr_t offset_imm, LiftoffRegister src,
                                    StoreType type, LiftoffRegList pinned,
                                    bool /* i64_offset */) {
   DCHECK_LE(offset_imm, std::numeric_limits<int32_t>::max());
@@ -826,7 +826,7 @@ enum Binop { kAdd, kSub, kAnd, kOr, kXor
 
 inline void AtomicAddOrSubOrExchange32(LiftoffAssembler* lasm, Binop binop,
                                        Register dst_addr, Register offset_reg,
-                                       uint32_t offset_imm,
+                                       uintptr_t offset_imm,
                                        LiftoffRegister value,
                                        LiftoffRegister result, StoreType type) {
   DCHECK_EQ(value, result);
@@ -894,7 +894,7 @@ inline void AtomicAddOrSubOrExchange32(L
 }
 
 inline void AtomicBinop32(LiftoffAssembler* lasm, Binop op, Register dst_addr,
-                          Register offset_reg, uint32_t offset_imm,
+                          Register offset_reg, uintptr_t offset_imm,
                           LiftoffRegister value, LiftoffRegister result,
                           StoreType type) {
   DCHECK_EQ(value, result);
@@ -1009,7 +1009,7 @@ inline void AtomicBinop32(LiftoffAssembl
 }
 
 inline void AtomicBinop64(LiftoffAssembler* lasm, Binop op, Register dst_addr,
-                          Register offset_reg, uint32_t offset_imm,
+                          Register offset_reg, uintptr_t offset_imm,
                           LiftoffRegister value, LiftoffRegister result) {
   // We need {ebx} here, which is the root register. As the root register it
   // needs special treatment. As we use {ebx} directly in the code below, we
@@ -1105,7 +1105,7 @@ inline void AtomicBinop64(LiftoffAssembl
 }  // namespace liftoff
 
 void LiftoffAssembler::AtomicAdd(Register dst_addr, Register offset_reg,
-                                 uint32_t offset_imm, LiftoffRegister value,
+                                 uintptr_t offset_imm, LiftoffRegister value,
                                  LiftoffRegister result, StoreType type,
                                  bool /* i64_offset */) {
   if (type.value() == StoreType::kI64Store) {
@@ -1119,7 +1119,7 @@ void LiftoffAssembler::AtomicAdd(Registe
 }
 
 void LiftoffAssembler::AtomicSub(Register dst_addr, Register offset_reg,
-                                 uint32_t offset_imm, LiftoffRegister value,
+                                 uintptr_t offset_imm, LiftoffRegister value,
                                  LiftoffRegister result, StoreType type,
                                  bool /* i64_offset */) {
   if (type.value() == StoreType::kI64Store) {
@@ -1132,7 +1132,7 @@ void LiftoffAssembler::AtomicSub(Registe
 }
 
 void LiftoffAssembler::AtomicAnd(Register dst_addr, Register offset_reg,
-                                 uint32_t offset_imm, LiftoffRegister value,
+                                 uintptr_t offset_imm, LiftoffRegister value,
                                  LiftoffRegister result, StoreType type,
                                  bool /* i64_offset */) {
   if (type.value() == StoreType::kI64Store) {
@@ -1146,7 +1146,7 @@ void LiftoffAssembler::AtomicAnd(Registe
 }
 
 void LiftoffAssembler::AtomicOr(Register dst_addr, Register offset_reg,
-                                uint32_t offset_imm, LiftoffRegister value,
+                                uintptr_t offset_imm, LiftoffRegister value,
                                 LiftoffRegister result, StoreType type,
                                 bool /* i64_offset */) {
   if (type.value() == StoreType::kI64Store) {
@@ -1160,7 +1160,7 @@ void LiftoffAssembler::AtomicOr(Register
 }
 
 void LiftoffAssembler::AtomicXor(Register dst_addr, Register offset_reg,
-                                 uint32_t offset_imm, LiftoffRegister value,
+                                 uintptr_t offset_imm, LiftoffRegister value,
                                  LiftoffRegister result, StoreType type,
                                  bool /* i64_offset */) {
   if (type.value() == StoreType::kI64Store) {
@@ -1174,7 +1174,7 @@ void LiftoffAssembler::AtomicXor(Registe
 }
 
 void LiftoffAssembler::AtomicExchange(Register dst_addr, Register offset_reg,
-                                      uint32_t offset_imm,
+                                      uintptr_t offset_imm,
                                       LiftoffRegister value,
                                       LiftoffRegister result, StoreType type,
                                       bool /* i64_offset */) {
@@ -1189,7 +1189,7 @@ void LiftoffAssembler::AtomicExchange(Re
 }
 
 void LiftoffAssembler::AtomicCompareExchange(
-    Register dst_addr, Register offset_reg, uint32_t offset_imm,
+    Register dst_addr, Register offset_reg, uintptr_t offset_imm,
     LiftoffRegister expected, LiftoffRegister new_value, LiftoffRegister result,
     StoreType type, bool /* i64_offset */) {
   // We expect that the offset has already been added to {dst_addr}, and no
