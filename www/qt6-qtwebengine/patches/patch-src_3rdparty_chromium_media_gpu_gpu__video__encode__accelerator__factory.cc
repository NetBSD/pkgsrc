$NetBSD: patch-src_3rdparty_chromium_media_gpu_gpu__video__encode__accelerator__factory.cc,v 1.2 2026/04/30 06:39:41 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/media/gpu/gpu_video_encode_accelerator_factory.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/media/gpu/gpu_video_encode_accelerator_factory.cc
@@ -164,7 +164,7 @@ std::vector<VEAFactoryFunction> GetVEAFa
   }
 
 #if BUILDFLAG(USE_VAAPI)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(kAcceleratedVideoEncodeLinux)) {
     vea_factory_functions->push_back(base::BindRepeating(&CreateVaapiVEA));
   }
@@ -172,7 +172,7 @@ std::vector<VEAFactoryFunction> GetVEAFa
   vea_factory_functions->push_back(base::BindRepeating(&CreateVaapiVEA));
 #endif
 #elif BUILDFLAG(USE_V4L2_CODEC)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(kAcceleratedVideoEncodeLinux)) {
     vea_factory_functions->push_back(base::BindRepeating(&CreateV4L2VEA));
   }
