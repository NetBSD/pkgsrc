$NetBSD: patch-media_gpu_test_video__frame__validator.cc,v 1.32 2026/11/08 15:39:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/test/video_frame_validator.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ media/gpu/test/video_frame_validator.cc
@@ -29,7 +29,7 @@
 #include "media/media_buildflags.h"
 #include "testing/gtest/include/gtest/gtest.h"
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <sys/mman.h>
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
 
