$NetBSD: patch-media_gpu_test_video__frame__file__writer.cc,v 1.7 2025/09/12 16:02:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/test/video_frame_file_writer.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ media/gpu/test/video_frame_file_writer.cc
@@ -25,7 +25,7 @@
 #include "testing/gtest/include/gtest/gtest.h"
 #include "ui/gfx/codec/png_codec.h"
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <sys/mman.h>
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
 
