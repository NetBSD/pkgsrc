$NetBSD: patch-base_files_important__file__writer__cleaner.cc,v 1.26 2026/09/22 13:41:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/files/important_file_writer_cleaner.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ base/files/important_file_writer_cleaner.cc
@@ -27,7 +27,8 @@ namespace base {
 namespace {
 
 base::Time GetUpperBoundTime() {
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_FUCHSIA)
+// needed because of .CreationTime() pledge
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   // If process creation time is not available then use instance creation
   // time as the upper-bound for old files. Modification times may be
   // rounded-down to coarse-grained increments, e.g. FAT has 2s granularity,
