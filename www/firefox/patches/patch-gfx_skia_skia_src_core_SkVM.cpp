$NetBSD: patch-gfx_skia_skia_src_core_SkVM.cpp,v 1.2 2022/07/20 21:41:39 nia Exp $

Work with PaX MPROTECT on NetBSD by stating that we will later make this memory
block executable.

--- gfx/skia/skia/src/core/SkVM.cpp.orig	2022-07-05 12:21:05.000000000 +0000
+++ gfx/skia/skia/src/core/SkVM.cpp
@@ -2076,7 +2076,11 @@ namespace skvm {
         // Allocate space that we can remap as executable.
         const size_t page = sysconf(_SC_PAGESIZE);
         fJITSize = ((a.size() + page - 1) / page) * page;  // mprotect works at page granularity.
+#ifdef PROT_MPROTECT
+        fJITBuf = mmap(nullptr,fJITSize, PROT_READ|PROT_WRITE|PROT_MPROTECT(PROT_EXEC), MAP_ANONYMOUS|MAP_PRIVATE, -1,0);
+#else
         fJITBuf = mmap(nullptr,fJITSize, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_PRIVATE, -1,0);
+#endif
 
         // Assemble the program for real.
         a = Assembler{fJITBuf};
