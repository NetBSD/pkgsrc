$NetBSD: patch-base_files_scoped__file.cc,v 1.14 2026/01/19 16:14:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/files/scoped_file.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ base/files/scoped_file.cc
@@ -32,7 +32,7 @@ void ScopedFDCloseTraits::Free(int fd) {
   int ret = IGNORE_EINTR(close(fd));
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_APPLE) || \
-    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // NB: Some file descriptors can return errors from close() e.g. network
   // filesystems such as NFS and Linux input devices. On Linux, macOS, and
   // Fuchsia's POSIX layer, errors from close other than EBADF do not indicate
