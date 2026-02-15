$NetBSD: patch-base_files_dir__reader__posix.h,v 1.15 2026/02/15 09:03:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/files/dir_reader_posix.h.orig	2026-02-03 22:07:10.000000000 +0000
+++ base/files/dir_reader_posix.h
@@ -17,7 +17,7 @@
 // seems worse than falling back to enumerating all file descriptors so we will
 // probably never implement this on the Mac.
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "base/files/dir_reader_linux.h"
 #else
 #include "base/files/dir_reader_fallback.h"
@@ -25,7 +25,7 @@
 
 namespace base {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 typedef DirReaderLinux DirReaderPosix;
 #else
 typedef DirReaderFallback DirReaderPosix;
