$NetBSD: patch-gfx_skia_skia_src_core_SkVM.cpp,v 1.1 2023/09/11 12:33:25 ryoon Exp $

Work with PaX MPROTECT on NetBSD by stating that we will later make this memory
block executable.

https://bugzilla.mozilla.org/show_bug.cgi?id=1811913

--- gfx/skia/skia/src/core/SkVM.cpp.orig	2023-05-25 21:19:29.000000000 +0000
+++ gfx/skia/skia/src/core/SkVM.cpp
@@ -57,7 +57,11 @@ bool gSkVMJITViaDylib{false};
             // mprotect doesn't round up for you, and instead requires *len is at page granularity.
             const size_t page = sysconf(_SC_PAGESIZE);
             *len = ((*len + page - 1) / page) * page;
+#ifdef PROT_MPROTECT
+            return mmap(nullptr,*len, PROT_READ|PROT_WRITE|PROT_MPROTECT(PROT_EXEC), MAP_ANONYMOUS|MAP_PRIVATE, -1,0);
+#else
             return mmap(nullptr,*len, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_PRIVATE, -1,0);
+#endif
         }
         static void remap_as_executable(void* ptr, size_t len) {
             mprotect(ptr, len, PROT_READ|PROT_EXEC);
