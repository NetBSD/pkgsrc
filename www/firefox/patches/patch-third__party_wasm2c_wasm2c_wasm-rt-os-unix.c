$NetBSD: patch-third__party_wasm2c_wasm2c_wasm-rt-os-unix.c,v 1.3 2022/12/23 12:35:05 nia Exp $

Work with PaX MPROTECT on NetBSD by stating that we will later make this memory
block executable.

--- third_party/wasm2c/wasm2c/wasm-rt-os-unix.c.orig	2022-11-28 16:49:17.000000000 +0000
+++ third_party/wasm2c/wasm2c/wasm-rt-os-unix.c
@@ -48,6 +48,12 @@ void* os_mmap(void* hint, size_t size, i
     /* At most 16 G is allowed */
     return NULL;
 
+#ifdef PROT_MPROTECT
+    map_prot |= PROT_MPROTECT(PROT_READ);
+    map_prot |= PROT_MPROTECT(PROT_WRITE);
+    map_prot |= PROT_MPROTECT(PROT_EXEC);
+#endif
+
   if (prot & MMAP_PROT_READ)
     map_prot |= PROT_READ;
 
