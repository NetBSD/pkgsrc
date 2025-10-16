$NetBSD: patch-media_gpu_test_video__frame__validator.cc,v 1.8 2025/10/16 19:43:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/test/video_frame_validator.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ media/gpu/test/video_frame_validator.cc
@@ -29,7 +29,7 @@
 #include "media/media_buildflags.h"
 #include "testing/gtest/include/gtest/gtest.h"
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <sys/mman.h>
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
 
