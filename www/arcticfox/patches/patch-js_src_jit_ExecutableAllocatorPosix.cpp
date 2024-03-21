$NetBSD: patch-js_src_jit_ExecutableAllocatorPosix.cpp,v 1.1 2024/03/21 15:11:51 nia Exp $

PaX MPROTECT safety for NetBSD.

--- js/src/jit/ExecutableAllocatorPosix.cpp.orig	2024-03-21 14:18:03.401738129 +0000
+++ js/src/jit/ExecutableAllocatorPosix.cpp
@@ -48,6 +48,9 @@ js::jit::AllocateExecutableMemory(void* 
                                   size_t pageSize)
 {
     MOZ_ASSERT(bytes % pageSize == 0);
+#ifdef PROT_MPROTECT
+    permissions |= PROT_MPROTECT(PROT_READ | PROT_WRITE | PROT_EXEC);
+#endif
     void* p = MozTaggedAnonymousMmap(addr, bytes, permissions, MAP_PRIVATE | MAP_ANON, -1, 0, tag);
     return p == MAP_FAILED ? nullptr : p;
 }
