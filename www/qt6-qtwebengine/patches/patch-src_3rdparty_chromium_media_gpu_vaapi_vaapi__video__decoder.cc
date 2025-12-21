$NetBSD: patch-src_3rdparty_chromium_media_gpu_vaapi_vaapi__video__decoder.cc,v 1.1 2025/12/21 09:38:32 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/media/gpu/vaapi/vaapi_video_decoder.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/media/gpu/vaapi/vaapi_video_decoder.cc
@@ -785,7 +785,7 @@ void VaapiVideoDecoder::ApplyResolutionC
   const gfx::Size decoder_natural_size =
       aspect_ratio_.GetNaturalSize(decoder_visible_rect);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::optional<DmabufVideoFramePool::CreateFrameCB> allocator =
       base::BindRepeating(&AllocateCustomFrameProxy, weak_this_);
   std::vector<ImageProcessor::PixelLayoutCandidate> candidates = {
