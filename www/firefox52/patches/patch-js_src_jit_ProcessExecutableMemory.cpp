$NetBSD: patch-js_src_jit_ProcessExecutableMemory.cpp,v 1.1 2020/11/11 11:15:38 nia Exp $

PaX MPROTECT safety for NetBSD.

--- js/src/jit/ProcessExecutableMemory.cpp.orig	2018-06-21 18:53:54.000000000 +0000
+++ js/src/jit/ProcessExecutableMemory.cpp
@@ -288,8 +288,15 @@ ReserveProcessExecutableMemory(size_t by
     // Note that randomAddr is just a hint: if the address is not available
     // mmap will pick a different address.
     void* randomAddr = ComputeRandomAllocationAddress();
+#ifdef PROT_MPROTECT
+    void* p = MozTaggedAnonymousMmap(randomAddr, bytes,
+                                    PROT_NONE | PROT_MPROTECT(PROT_EXEC | PROT_WRITE | PROT_READ),
+                                    MAP_PRIVATE | MAP_ANON,
+                                     -1, 0, "js-executable-memory");
+#else
     void* p = MozTaggedAnonymousMmap(randomAddr, bytes, PROT_NONE, MAP_PRIVATE | MAP_ANON,
                                      -1, 0, "js-executable-memory");
+#endif
     if (p == MAP_FAILED)
         return nullptr;
     return p;
@@ -316,9 +323,17 @@ ProtectionSettingToFlags(ProtectionSetti
 static void
 CommitPages(void* addr, size_t bytes, ProtectionSetting protection)
 {
+#ifdef PROT_MPROTECT
+    void* p = MozTaggedAnonymousMmap(addr, bytes,
+                                     ProtectionSettingToFlags(protection) |
+                                     PROT_MPROTECT(PROT_EXEC | PROT_WRITE | PROT_READ),
+                                     MAP_FIXED | MAP_PRIVATE | MAP_ANON,
+                                     -1, 0, "js-executable-memory");
+#else
     void* p = MozTaggedAnonymousMmap(addr, bytes, ProtectionSettingToFlags(protection),
                                      MAP_FIXED | MAP_PRIVATE | MAP_ANON,
                                      -1, 0, "js-executable-memory");
+#endif
     MOZ_RELEASE_ASSERT(addr == p);
 }
 
