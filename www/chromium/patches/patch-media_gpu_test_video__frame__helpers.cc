$NetBSD: patch-media_gpu_test_video__frame__helpers.cc,v 1.33 2026/11/19 19:46:03 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/test/video_frame_helpers.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ media/gpu/test/video_frame_helpers.cc
@@ -22,7 +22,7 @@
 #include "third_party/libyuv/include/libyuv.h"
 #include "ui/gfx/gpu_memory_buffer_handle.h"
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <sys/mman.h>
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
 
