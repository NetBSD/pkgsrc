$NetBSD: patch-media_gpu_gpu__video__encode__accelerator__factory.cc,v 1.19 2026/05/10 15:30:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/gpu_video_encode_accelerator_factory.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ media/gpu/gpu_video_encode_accelerator_factory.cc
@@ -67,7 +67,7 @@ std::unique_ptr<VideoEncodeAccelerator> 
 }
 #elif BUILDFLAG(USE_VAAPI)
 std::unique_ptr<VideoEncodeAccelerator> CreateVaapiVEA() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!base::FeatureList::IsEnabled(kAcceleratedVideoEncodeLinux)) {
     return nullptr;
   }
