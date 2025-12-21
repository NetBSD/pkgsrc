$NetBSD: patch-src_3rdparty_chromium_media_gpu_chromeos_libyuv__image__processor__backend.cc,v 1.1 2025/12/21 09:38:32 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/media/gpu/chromeos/libyuv_image_processor_backend.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/media/gpu/chromeos/libyuv_image_processor_backend.cc
@@ -53,7 +53,7 @@ static constexpr struct {
 #define CONV(in, out, trans, result) \
   {Fourcc::in, Fourcc::out, Transform::trans, SupportResult::result}
     // Conversion.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     CONV(NV12, AR24, kConversion, Supported),
 #endif
     CONV(NV12, NV12, kConversion, Supported),
@@ -420,7 +420,7 @@ int LibYUVImageProcessorBackend::DoConve
           fr->GetWritableVisibleData(VideoFrame::Plane::kUV)), \
       fr->stride(VideoFrame::Plane::kUV)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define ARGB_DATA(fr)                                   \
   fr->GetWritableVisibleData(VideoFrame::Plane::kARGB), \
       fr->stride(VideoFrame::Plane::kARGB)
@@ -582,7 +582,7 @@ int LibYUVImageProcessorBackend::DoConve
     }
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (output->format() == PIXEL_FORMAT_ARGB) {
     if (input_config_.fourcc == Fourcc(Fourcc::NV12)) {
       return LIBYUV_FUNC(NV12ToARGB, Y_UV_DATA(input),
