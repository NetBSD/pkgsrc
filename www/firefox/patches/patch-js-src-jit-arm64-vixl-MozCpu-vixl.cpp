$NetBSD: patch-js-src-jit-arm64-vixl-MozCpu-vixl.cpp,v 1.2 2024/02/22 15:12:50 ryoon Exp $

Add NetBSD support.

--- js/src/jit/arm64/vixl/MozCpu-vixl.cpp.orig	2024-02-13 14:50:57.324257195 +0000
+++ js/src/jit/arm64/vixl/MozCpu-vixl.cpp
@@ -110,7 +110,7 @@ void CPU::EnsureIAndDCacheCoherency(void
   FlushInstructionCache(GetCurrentProcess(), address, length);
 #elif defined(XP_DARWIN)
   sys_icache_invalidate(address, length);
-#elif defined(__aarch64__) && (defined(__linux__) || defined(__android__) || defined(__FreeBSD__))
+#elif defined(__aarch64__) && (defined(__linux__) || defined(__android__) || defined(__FreeBSD__) || defined(__NetBSD__))
   // Implement the cache synchronisation for all targets where AArch64 is the
   // host, even if we're building the simulator for an AAarch64 host. This
   // allows for cases where the user wants to simulate code as well as run it
