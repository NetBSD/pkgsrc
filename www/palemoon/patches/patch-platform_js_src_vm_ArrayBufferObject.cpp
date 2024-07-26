$NetBSD: patch-platform_js_src_vm_ArrayBufferObject.cpp,v 1.1 2024/07/26 08:05:23 nia Exp $

PaX MPROTECT safety for NetBSD.

--- platform/js/src/vm/ArrayBufferObject.cpp.orig	2024-07-25 14:21:16.217887303 +0000
+++ platform/js/src/vm/ArrayBufferObject.cpp
@@ -644,7 +644,12 @@ WasmArrayRawBuffer::Allocate(uint32_t nu
         return nullptr;
     }
 # else  // XP_WIN
-    void* data = MozTaggedAnonymousMmap(nullptr, (size_t) mappedSizeWithHeader, PROT_NONE,
+    void* data = MozTaggedAnonymousMmap(nullptr, (size_t) mappedSizeWithHeader,
+#ifdef PROT_MPROTECT
+                                        PROT_MPROTECT(PROT_EXEC | PROT_WRITE | PROT_READ),
+#else
+                                        PROT_NONE,
+#endif
                                         MAP_PRIVATE | MAP_ANON, -1, 0, "wasm-reserved");
     if (data == MAP_FAILED)
         return nullptr;
