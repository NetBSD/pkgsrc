$NetBSD: patch-js_src_vm_ArrayBufferObject.cpp,v 1.1 2024/03/21 15:11:51 nia Exp $

PaX MPROTECT safety for NetBSD.

--- js/src/vm/ArrayBufferObject.cpp.orig	2024-03-21 14:19:53.458599709 +0000
+++ js/src/vm/ArrayBufferObject.cpp
@@ -393,7 +393,11 @@ ReleaseWasmMappedMemory(void* base)
 static void*
 AllocateWasmMappedMemory(uint32_t numBytes)
 {
-    void* data = MozTaggedAnonymousMmap(nullptr, wasm::MappedSize, PROT_NONE,
+    int prot = PROT_NONE;
+#ifdef PROT_MPROTECT
+    prot |= PROT_MPROTECT(PROT_READ | PROT_WRITE | PROT_EXEC);
+#endif
+    void* data = MozTaggedAnonymousMmap(nullptr, wasm::MappedSize, prot,
                                         MAP_PRIVATE | MAP_ANON, -1, 0, "wasm-reserved");
     if (data == MAP_FAILED)
         return nullptr;
