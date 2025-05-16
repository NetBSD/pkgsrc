$NetBSD: patch-media_video_fake__gpu__memory__buffer.h,v 1.1 2025/05/16 16:08:28 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/video/fake_gpu_memory_buffer.h.orig	2025-05-05 19:21:24.000000000 +0000
+++ media/video/fake_gpu_memory_buffer.h
@@ -13,7 +13,7 @@
 
 namespace media {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // This method is used by tests to create a fake pixmap handle instead of
 // creating a FakeGpuMemoryBuffer. Once all tests are converted to use it,
 // FakeGpuMemoryBuffer will be removed and this file will be renamed
