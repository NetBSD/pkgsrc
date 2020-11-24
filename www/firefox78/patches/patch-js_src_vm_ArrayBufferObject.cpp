$NetBSD: patch-js_src_vm_ArrayBufferObject.cpp,v 1.1.2.2 2020/11/24 18:29:25 bsiegert Exp $

PaX MPROTECT safety for NetBSD.

--- js/src/vm/ArrayBufferObject.cpp.orig	2020-10-27 23:48:08.000000000 +0000
+++ js/src/vm/ArrayBufferObject.cpp
@@ -165,9 +165,17 @@ void* js::MapBufferMemory(size_t mappedS
     return nullptr;
   }
 #else   // XP_WIN
+
+#ifdef PROT_MPROTECT
+  void* data =
+      MozTaggedAnonymousMmap(nullptr, mappedSize,
+                             PROT_MPROTECT(PROT_EXEC | PROT_WRITE | PROT_READ),
+                             MAP_PRIVATE | MAP_ANON, -1, 0, "wasm-reserved");
+#else
   void* data =
       MozTaggedAnonymousMmap(nullptr, mappedSize, PROT_NONE,
                              MAP_PRIVATE | MAP_ANON, -1, 0, "wasm-reserved");
+#endif
   if (data == MAP_FAILED) {
     return nullptr;
   }
