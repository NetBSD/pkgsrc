$NetBSD: patch-platform_js_src_jit_ProcessExecutableMemory.cpp,v 1.1 2024/07/26 08:05:23 nia Exp $

PaX MPROTECT safety for NetBSD.

--- platform/js/src/jit/ProcessExecutableMemory.cpp.orig	2024-07-25 14:18:46.578160361 +0000
+++ platform/js/src/jit/ProcessExecutableMemory.cpp
@@ -287,8 +287,15 @@ ReserveProcessExecutableMemory(size_t by
     // Note that randomAddr is just a hint: if the address is not available
     // mmap will pick a different address.
     void* randomAddr = ComputeRandomAllocationAddress();
+#ifdef PROT_MPROTECT
+    void* p = MozTaggedAnonymousMmap(randomAddr, bytes,
+                                     PROT_MPROTECT(PROT_EXEC | PROT_WRITE | PROT_READ),
+                                     MAP_PRIVATE | MAP_ANON,
+                                     -1, 0, "js-executable-memory");
+#else
     void* p = MozTaggedAnonymousMmap(randomAddr, bytes, PROT_NONE, MAP_PRIVATE | MAP_ANON,
                                      -1, 0, "js-executable-memory");
+#endif
     if (p == MAP_FAILED)
         return nullptr;
     return p;
@@ -315,7 +322,13 @@ ProtectionSettingToFlags(ProtectionSetti
 static void
 CommitPages(void* addr, size_t bytes, ProtectionSetting protection)
 {
-    void* p = MozTaggedAnonymousMmap(addr, bytes, ProtectionSettingToFlags(protection),
+    void* p = MozTaggedAnonymousMmap(addr, bytes,
+#ifdef PROT_MPROTECT
+                                     ProtectionSettingToFlags(protection) |
+                                     PROT_MPROTECT(PROT_EXEC | PROT_WRITE | PROT_READ),
+#else
+                                     ProtectionSettingToFlags(protection),
+#endif
                                      MAP_FIXED | MAP_PRIVATE | MAP_ANON,
                                      -1, 0, "js-executable-memory");
     MOZ_RELEASE_ASSERT(addr == p);
