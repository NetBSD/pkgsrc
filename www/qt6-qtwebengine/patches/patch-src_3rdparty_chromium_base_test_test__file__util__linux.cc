$NetBSD: patch-src_3rdparty_chromium_base_test_test__file__util__linux.cc,v 1.1 2025/12/21 09:38:16 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/test/test_file_util_linux.cc.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/base/test/test_file_util_linux.cc
@@ -56,9 +56,11 @@ bool EvictFileFromSystemCache(const File
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
 
