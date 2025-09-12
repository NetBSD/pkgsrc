$NetBSD: patch-media_gpu_gpu__video__encode__accelerator__factory.cc,v 1.7 2025/09/12 16:02:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/gpu_video_encode_accelerator_factory.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ media/gpu/gpu_video_encode_accelerator_factory.cc
@@ -162,7 +162,7 @@ std::vector<VEAFactoryFunction> GetVEAFa
   }
 
 #if BUILDFLAG(USE_VAAPI)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(kAcceleratedVideoEncodeLinux)) {
     vea_factory_functions->push_back(base::BindRepeating(&CreateVaapiVEA));
   }
@@ -170,7 +170,7 @@ std::vector<VEAFactoryFunction> GetVEAFa
   vea_factory_functions->push_back(base::BindRepeating(&CreateVaapiVEA));
 #endif
 #elif BUILDFLAG(USE_V4L2_CODEC)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(kAcceleratedVideoEncodeLinux)) {
     vea_factory_functions->push_back(base::BindRepeating(&CreateV4L2VEA));
   }
