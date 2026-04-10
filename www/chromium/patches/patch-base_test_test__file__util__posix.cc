$NetBSD: patch-base_test_test__file__util__posix.cc,v 1.17 2026/04/10 17:31:47 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/test/test_file_util_posix.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ base/test/test_file_util_posix.cc
@@ -66,7 +66,7 @@ void SyncPageCacheToDisk() {
 }
 
 #if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_APPLE) && \
-    !BUILDFLAG(IS_ANDROID)
+    !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_BSD)
 bool EvictFileFromSystemCache(const FilePath& file) {
   // There doesn't seem to be a POSIX way to cool the disk cache.
   NOTIMPLEMENTED();
