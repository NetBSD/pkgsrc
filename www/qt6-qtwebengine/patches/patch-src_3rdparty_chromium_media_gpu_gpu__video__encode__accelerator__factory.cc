$NetBSD: patch-src_3rdparty_chromium_media_gpu_gpu__video__encode__accelerator__factory.cc,v 1.3 2026/08/18 18:26:06 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/media/gpu/gpu_video_encode_accelerator_factory.cc.orig	2026-08-11 12:42:19.000000000 +0000
+++ src/3rdparty/chromium/media/gpu/gpu_video_encode_accelerator_factory.cc
@@ -155,7 +155,7 @@ std::vector<VEAFactoryFunction> CreateVE
     const gpu::GPUInfo::GPUDevice& gpu_device) {
   std::vector<VEAFactoryFunction> funcs;
 #if BUILDFLAG(USE_VAAPI)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(kAcceleratedVideoEncodeLinux)) {
     funcs.push_back(base::BindRepeating(&CreateVaapiVEA));
   }
@@ -163,7 +163,7 @@ std::vector<VEAFactoryFunction> CreateVE
   funcs.push_back(base::BindRepeating(&CreateVaapiVEA));
 #endif
 #elif BUILDFLAG(USE_V4L2_CODEC)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(kAcceleratedVideoEncodeLinux)) {
     funcs.push_back(base::BindRepeating(&CreateV4L2VEA));
   }
