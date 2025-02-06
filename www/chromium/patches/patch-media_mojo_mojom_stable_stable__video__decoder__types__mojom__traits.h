$NetBSD: patch-media_mojo_mojom_stable_stable__video__decoder__types__mojom__traits.h,v 1.1 2025/02/06 09:58:13 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/mojo/mojom/stable/stable_video_decoder_types_mojom_traits.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ media/mojo/mojom/stable/stable_video_decoder_types_mojom_traits.h
@@ -695,7 +695,7 @@ struct StructTraits<media::stable::mojom
   static const gfx::GpuMemoryBufferId& id(
       const gfx::GpuMemoryBufferHandle& input);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static gfx::NativePixmapHandle platform_handle(
       gfx::GpuMemoryBufferHandle& input);
 #else
