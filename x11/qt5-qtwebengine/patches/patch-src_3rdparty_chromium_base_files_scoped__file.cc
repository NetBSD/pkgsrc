$NetBSD: patch-src_3rdparty_chromium_base_files_scoped__file.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/files/scoped_file.cc.orig	2020-06-25 09:31:18.000000000 +0000
+++ src/3rdparty/chromium/base/files/scoped_file.cc
@@ -31,7 +31,7 @@ void ScopedFDCloseTraits::Free(int fd) {
   int ret = IGNORE_EINTR(close(fd));
 
 #if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_FUCHSIA) || \
-    defined(OS_ANDROID)
+    defined(OS_ANDROID) || defined(OS_BSD)
   // NB: Some file descriptors can return errors from close() e.g. network
   // filesystems such as NFS and Linux input devices. On Linux, macOS, and
   // Fuchsia's POSIX layer, errors from close other than EBADF do not indicate
