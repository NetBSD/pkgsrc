$NetBSD: patch-media_gpu_test_video__frame__file__writer.cc,v 1.19 2026/05/10 15:30:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/test/video_frame_file_writer.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ media/gpu/test/video_frame_file_writer.cc
@@ -22,7 +22,7 @@
 #include "testing/gtest/include/gtest/gtest.h"
 #include "ui/gfx/codec/png_codec.h"
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <sys/mman.h>
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
 
