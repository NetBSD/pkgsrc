$NetBSD: patch-base_test_test__file__util__linux.cc,v 1.15 2026/02/15 09:03:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/test/test_file_util_linux.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ base/test/test_file_util_linux.cc
@@ -57,9 +57,11 @@ bool EvictFileFromSystemCache(const File
   if (fdatasync(fd.get()) != 0) {
     return false;
   }
+#if !BUILDFLAG(IS_BSD)
   if (posix_fadvise(fd.get(), 0, 0, POSIX_FADV_DONTNEED) != 0) {
     return false;
   }
+#endif
   return true;
 }
 
