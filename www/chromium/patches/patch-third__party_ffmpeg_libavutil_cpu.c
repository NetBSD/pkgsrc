$NetBSD: patch-third__party_ffmpeg_libavutil_cpu.c,v 1.14 2026/01/19 16:14:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/ffmpeg/libavutil/cpu.c.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/ffmpeg/libavutil/cpu.c
@@ -38,10 +38,7 @@
 #if HAVE_GETPROCESSAFFINITYMASK || HAVE_WINRT
 #include <windows.h>
 #endif
-#if HAVE_SYSCTL
-#if HAVE_SYS_PARAM_H
-#include <sys/param.h>
-#endif
+#if HAVE_SYSCTL && !defined(__OpenBSD__)
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
