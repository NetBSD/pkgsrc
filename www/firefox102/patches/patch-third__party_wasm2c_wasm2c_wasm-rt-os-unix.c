$NetBSD: patch-third__party_wasm2c_wasm2c_wasm-rt-os-unix.c,v 1.1 2022/07/21 23:56:39 nia Exp $

Work with PaX MPROTECT on NetBSD by stating that we will later make this memory
block executable.

--- third_party/wasm2c/wasm2c/wasm-rt-os-unix.c.orig	2022-07-05 12:21:22.000000000 +0000
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
 
@@ -279,4 +285,4 @@ void os_print_last_error(const char* msg
 #else
   // https://stackoverflow.com/questions/26541150/warning-iso-c-forbids-an-empty-translation-unit
   typedef int make_iso_compilers_happy;
-#endif
\ No newline at end of file
+#endif
