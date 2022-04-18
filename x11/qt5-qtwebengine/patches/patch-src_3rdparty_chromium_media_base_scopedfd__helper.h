$NetBSD: patch-src_3rdparty_chromium_media_base_scopedfd__helper.h,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/media/base/scopedfd_helper.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/media/base/scopedfd_helper.h
@@ -14,7 +14,7 @@ namespace media {
 // since the only current user is V4L2 we are limiting the scope to OS_LINUX so
 // the binary size does not inflate on non-using systems. Feel free to adapt
 // this and BUILD.gn as our needs evolve.
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 // Return a new vector containing duplicates of |fds|, or PCHECKs in case of an
 // error.
