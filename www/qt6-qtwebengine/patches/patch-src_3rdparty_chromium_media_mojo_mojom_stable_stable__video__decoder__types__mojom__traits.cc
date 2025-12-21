$NetBSD: patch-src_3rdparty_chromium_media_mojo_mojom_stable_stable__video__decoder__types__mojom__traits.cc,v 1.1 2025/12/21 09:38:33 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/media/mojo/mojom/stable/stable_video_decoder_types_mojom_traits.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/media/mojo/mojom/stable/stable_video_decoder_types_mojom_traits.cc
@@ -841,7 +841,7 @@ const gfx::GpuMemoryBufferId& StructTrai
   return input.id;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // static
 gfx::NativePixmapHandle StructTraits<
     media::stable::mojom::NativeGpuMemoryBufferHandleDataView,
@@ -862,7 +862,7 @@ bool StructTraits<media::stable::mojom::
 
   output->type = gfx::NATIVE_PIXMAP;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!data.ReadPlatformHandle(&output->native_pixmap_handle))
     return false;
   return true;
