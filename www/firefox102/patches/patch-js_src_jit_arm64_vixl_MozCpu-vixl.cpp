$NetBSD: patch-js_src_jit_arm64_vixl_MozCpu-vixl.cpp,v 1.3 2023/09/10 14:42:29 nia Exp $

Add NetBSD support.

--- js/src/jit/arm64/vixl/MozCpu-vixl.cpp.orig	2023-08-22 15:44:37.000000000 +0000
+++ js/src/jit/arm64/vixl/MozCpu-vixl.cpp
@@ -68,7 +68,7 @@ void CPU::SetUp() {
 
 
 uint32_t CPU::GetCacheType() {
-#if defined(__aarch64__) && (defined(__linux__) || defined(__android__))
+#if defined(__aarch64__) && (defined(__linux__) || defined(__android__) || defined(__NetBSD__))
   uint64_t cache_type_register;
   // Copy the content of the cache type register to a core register.
   __asm__ __volatile__ ("mrs %[ctr], ctr_el0"  // NOLINT
@@ -110,7 +110,7 @@ void CPU::EnsureIAndDCacheCoherency(void
   FlushInstructionCache(GetCurrentProcess(), address, length);
 #elif defined(XP_DARWIN)
   sys_icache_invalidate(address, length);
-#elif defined(__aarch64__) && (defined(__linux__) || defined(__android__))
+#elif defined(__aarch64__) && (defined(__linux__) || defined(__android__) || defined(__NetBSD__))
   // Implement the cache synchronisation for all targets where AArch64 is the
   // host, even if we're building the simulator for an AAarch64 host. This
   // allows for cases where the user wants to simulate code as well as run it
