$NetBSD: patch-js_src_jit_ProcessExecutableMemory.cpp,v 1.1 2025/04/14 15:33:04 nia Exp $

PaX MPROTECT support for NetBSD.

--- js/src/jit/ProcessExecutableMemory.cpp.orig	2024-12-13 00:29:16.000000000 +0000
+++ js/src/jit/ProcessExecutableMemory.cpp
@@ -292,8 +292,13 @@ ReserveProcessExecutableMemory(size_t by
     // Note that randomAddr is just a hint: if the address is not available
     // mmap will pick a different address.
     void* randomAddr = ComputeRandomAllocationAddress();
+#ifdef PROT_MPROTECT
+    void* p = MozTaggedAnonymousMmap(randomAddr, bytes, PROT_NONE | PROT_MPROTECT(PROT_READ | PROT_WRITE | PROT_EXEC), MAP_PRIVATE | MAP_ANON,
+                                     -1, 0, "js-executable-memory");
+#else
     void* p = MozTaggedAnonymousMmap(randomAddr, bytes, PROT_NONE, MAP_PRIVATE | MAP_ANON,
                                      -1, 0, "js-executable-memory");
+#endif
     if (p == MAP_FAILED)
         return nullptr;
     return p;
@@ -336,9 +341,15 @@ ProtectionSettingToFlags(ProtectionSetti
 static MOZ_MUST_USE bool
 CommitPages(void* addr, size_t bytes, ProtectionSetting protection)
 {
+#ifdef PROT_MPROTECT
+    void* p = MozTaggedAnonymousMmap(addr, bytes, ProtectionSettingToFlags(protection) | PROT_MPROTECT(PROT_READ | PROT_WRITE | PROT_EXEC),
+                                     MAP_FIXED | MAP_PRIVATE | MAP_ANON,
+                                     -1, 0, "js-executable-memory");
+#else
     void* p = MozTaggedAnonymousMmap(addr, bytes, ProtectionSettingToFlags(protection),
                                      MAP_FIXED | MAP_PRIVATE | MAP_ANON,
                                      -1, 0, "js-executable-memory");
+#endif
     if (p == MAP_FAILED)
         return false;
     MOZ_RELEASE_ASSERT(p == addr);
@@ -350,9 +361,15 @@ DecommitPages(void* addr, size_t bytes)
 {
     // Use mmap with MAP_FIXED and PROT_NONE. Inspired by jemalloc's
     // pages_decommit.
+#ifdef PROT_MPROTECT
+    void* p = MozTaggedAnonymousMmap(addr, bytes, PROT_NONE | PROT_MPROTECT(PROT_READ | PROT_WRITE | PROT_EXEC),
+                                     MAP_FIXED | MAP_PRIVATE | MAP_ANON,
+                                     -1, 0, "js-executable-memory");
+#else
     void* p = MozTaggedAnonymousMmap(addr, bytes, PROT_NONE,
                                      MAP_FIXED | MAP_PRIVATE | MAP_ANON,
                                      -1, 0, "js-executable-memory");
+#endif
     MOZ_RELEASE_ASSERT(addr == p);
 }
 #endif
