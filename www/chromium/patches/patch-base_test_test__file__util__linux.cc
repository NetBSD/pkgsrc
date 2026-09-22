$NetBSD: patch-base_test_test__file__util__linux.cc,v 1.26 2026/09/22 13:41:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/test/test_file_util_linux.cc.orig	2026-09-14 22:17:16.000000000 +0000
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
 
