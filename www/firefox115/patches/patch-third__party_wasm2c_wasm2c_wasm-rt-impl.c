$NetBSD: patch-third__party_wasm2c_wasm2c_wasm-rt-impl.c,v 1.1 2023/09/11 12:33:25 ryoon Exp $

* I believe that this is insufficient.

--- third_party/wasm2c/wasm2c/wasm-rt-impl.c.orig	2023-05-25 21:19:41.000000000 +0000
+++ third_party/wasm2c/wasm2c/wasm-rt-impl.c
@@ -144,6 +144,11 @@ static void os_cleanup_signal_handler(vo
 #else
 static void* os_mmap(size_t size) {
   int map_prot = PROT_NONE;
+#ifdef PROT_MPROTECT
+    map_prot |= PROT_MPROTECT(PROT_READ);
+    map_prot |= PROT_MPROTECT(PROT_WRITE);
+    map_prot |= PROT_MPROTECT(PROT_EXEC);
+#endif
   int map_flags = MAP_ANONYMOUS | MAP_PRIVATE;
   uint8_t* addr = mmap(NULL, size, map_prot, map_flags, -1, 0);
   if (addr == MAP_FAILED)
