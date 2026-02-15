$NetBSD: patch-media_gpu_chromeos_libyuv__image__processor__backend.cc,v 1.15 2026/02/15 09:04:07 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/chromeos/libyuv_image_processor_backend.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ media/gpu/chromeos/libyuv_image_processor_backend.cc
@@ -52,7 +52,7 @@ static constexpr struct {
 #define CONV(in, out, trans, result) \
   {Fourcc::in, Fourcc::out, Transform::trans, SupportResult::result}
     // Conversion.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     CONV(NV12, AR24, kConversion, Supported),
 #endif
     CONV(NV12, NV12, kConversion, Supported),
@@ -411,7 +411,7 @@ int LibYUVImageProcessorBackend::DoConve
           fr->GetWritableVisibleData(VideoFrame::Plane::kUV)), \
       fr->stride(VideoFrame::Plane::kUV)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define ARGB_DATA(fr)                                   \
   fr->GetWritableVisibleData(VideoFrame::Plane::kARGB), \
       fr->stride(VideoFrame::Plane::kARGB)
@@ -573,7 +573,7 @@ int LibYUVImageProcessorBackend::DoConve
     }
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (output->format() == PIXEL_FORMAT_ARGB) {
     if (input_config_.fourcc == Fourcc(Fourcc::NV12)) {
       return LIBYUV_FUNC(NV12ToARGB, Y_UV_DATA(input),
