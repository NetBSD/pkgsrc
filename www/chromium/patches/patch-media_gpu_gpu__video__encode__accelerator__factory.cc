$NetBSD: patch-media_gpu_gpu__video__encode__accelerator__factory.cc,v 1.25 2026/09/02 13:13:32 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/gpu_video_encode_accelerator_factory.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ media/gpu/gpu_video_encode_accelerator_factory.cc
@@ -71,7 +71,7 @@ std::unique_ptr<VideoEncodeAccelerator> 
 
 #if BUILDFLAG(USE_VAAPI)
 std::unique_ptr<VideoEncodeAccelerator> CreateVaapiVEA() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!base::FeatureList::IsEnabled(kAcceleratedVideoEncodeLinux)) {
     return nullptr;
   }
