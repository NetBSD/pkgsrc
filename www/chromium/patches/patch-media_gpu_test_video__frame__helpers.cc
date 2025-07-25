$NetBSD: patch-media_gpu_test_video__frame__helpers.cc,v 1.4 2025/07/25 16:17:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/test/video_frame_helpers.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ media/gpu/test/video_frame_helpers.cc
@@ -23,7 +23,7 @@
 #include "ui/gfx/buffer_format_util.h"
 #include "ui/gfx/gpu_memory_buffer.h"
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <sys/mman.h>
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
 
