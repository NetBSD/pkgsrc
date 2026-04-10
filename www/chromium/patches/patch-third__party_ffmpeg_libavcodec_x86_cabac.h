$NetBSD: patch-third__party_ffmpeg_libavcodec_x86_cabac.h,v 1.17 2026/04/10 17:32:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/ffmpeg/libavcodec/x86/cabac.h.orig	2026-04-06 16:25:54.000000000 +0000
+++ third_party/ffmpeg/libavcodec/x86/cabac.h
@@ -31,7 +31,8 @@
 
 #if   (defined(__i386) && defined(__clang__) && (__clang_major__<2 || (__clang_major__==2 && __clang_minor__<10)))\
    || (                  !defined(__clang__) && defined(__llvm__) && __GNUC__==4 && __GNUC_MINOR__==2 && __GNUC_PATCHLEVEL__<=1)\
-   || (defined(__INTEL_COMPILER) && defined(_MSC_VER))
+   || (defined(__INTEL_COMPILER) && defined(_MSC_VER)) \
+   || ((defined(__FreeBSD__) || defined(__OpenBSD__)) && defined(__i386))
 #       define BROKEN_COMPILER 1
 #else
 #       define BROKEN_COMPILER 0
