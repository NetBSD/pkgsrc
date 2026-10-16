$NetBSD: patch-content_browser_gpu_compositor__util.cc,v 1.30 2026/10/16 15:30:53 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/gpu/compositor_util.cc.orig	2026-10-14 21:09:54.000000000 +0000
+++ content/browser/gpu/compositor_util.cc
@@ -144,7 +144,7 @@ std::vector<GpuFeatureData> GetGpuFeatur
       "video_decode",
       SafeGetFeatureStatus(
           gpu_feature_info, gpu::GPU_FEATURE_TYPE_ACCELERATED_VIDEO_DECODE,
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
           !base::FeatureList::IsEnabled(media::kAcceleratedVideoDecodeLinux) ||
 #endif  // BUILDFLAG(IS_LINUX)
               command_line.HasSwitch(switches::kDisableAcceleratedVideoDecode)),
@@ -156,7 +156,7 @@ std::vector<GpuFeatureData> GetGpuFeatur
       "video_encode",
       SafeGetFeatureStatus(
           gpu_feature_info, gpu::GPU_FEATURE_TYPE_ACCELERATED_VIDEO_ENCODE,
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
           !base::FeatureList::IsEnabled(media::kAcceleratedVideoEncodeLinux)),
 #else
           command_line.HasSwitch(switches::kDisableAcceleratedVideoEncode)),
@@ -218,7 +218,7 @@ std::vector<GpuFeatureData> GetGpuFeatur
                             ? gpu::kGpuFeatureStatusEnabled
                             : gpu::kGpuFeatureStatusDisabled);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   features.emplace_back(
       "webgpu_on_vk_via_gl_interop",
       SafeGetFeatureStatus(gpu_feature_info,
