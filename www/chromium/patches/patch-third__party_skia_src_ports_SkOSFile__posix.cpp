$NetBSD: patch-third__party_skia_src_ports_SkOSFile__posix.cpp,v 1.14 2026/01/19 16:14:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/skia/src/ports/SkOSFile_posix.cpp.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/skia/src/ports/SkOSFile_posix.cpp
@@ -25,7 +25,7 @@
 #endif
 
 void sk_fsync(FILE* f) {
-#if !defined(SK_BUILD_FOR_ANDROID) && !defined(__UCLIBC__) && !defined(_NEWLIB_VERSION)
+#if !defined(SK_BUILD_FOR_ANDROID) && !defined(__UCLIBC__) && !defined(_NEWLIB_VERSION) && !defined(__OpenBSD__)
     int fd = fileno(f);
     fsync(fd);
 #endif
