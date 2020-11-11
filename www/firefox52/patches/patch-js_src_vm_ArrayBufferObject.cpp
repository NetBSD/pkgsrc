$NetBSD: patch-js_src_vm_ArrayBufferObject.cpp,v 1.1 2020/11/11 11:15:38 nia Exp $

PaX MPROTECT safety for NetBSD.

--- js/src/vm/ArrayBufferObject.cpp.orig	2017-04-11 02:13:21.000000000 +0000
+++ js/src/vm/ArrayBufferObject.cpp
@@ -648,8 +648,14 @@ WasmArrayRawBuffer::Allocate(uint32_t nu
         return nullptr;
     }
 # else  // XP_WIN
+#ifdef PROT_MPROTECT
+    void* data = MozTaggedAnonymousMmap(nullptr, (size_t) mappedSizeWithHeader,
+                                        PROT_NONE | PROT_MPROTECT(PROT_EXEC | PROT_WRITE | PROT_READ),
+                                        MAP_PRIVATE | MAP_ANON, -1, 0, "wasm-reserved");
+#else
     void* data = MozTaggedAnonymousMmap(nullptr, (size_t) mappedSizeWithHeader, PROT_NONE,
                                         MAP_PRIVATE | MAP_ANON, -1, 0, "wasm-reserved");
+#endif
     if (data == MAP_FAILED)
         return nullptr;
 
