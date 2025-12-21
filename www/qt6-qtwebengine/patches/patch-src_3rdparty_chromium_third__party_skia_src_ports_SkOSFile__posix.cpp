$NetBSD: patch-src_3rdparty_chromium_third__party_skia_src_ports_SkOSFile__posix.cpp,v 1.1 2025/12/21 09:38:44 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/skia/src/ports/SkOSFile_posix.cpp.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/third_party/skia/src/ports/SkOSFile_posix.cpp
@@ -25,7 +25,7 @@
 #endif
 
 void sk_fsync(FILE* f) {
-#if !defined(SK_BUILD_FOR_ANDROID) && !defined(__UCLIBC__) && !defined(_NEWLIB_VERSION)
+#if !defined(SK_BUILD_FOR_ANDROID) && !defined(__UCLIBC__) && !defined(_NEWLIB_VERSION) && !defined(__OpenBSD__)
     int fd = fileno(f);
     fsync(fd);
 #endif
