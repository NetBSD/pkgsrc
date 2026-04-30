$NetBSD: patch-src_3rdparty_chromium_media_mojo_mojom_video__frame__mojom__traits.h,v 1.1 2026/04/30 06:39:41 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/media/mojo/mojom/video_frame_mojom_traits.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/media/mojo/mojom/video_frame_mojom_traits.h
@@ -21,7 +21,7 @@
 
 namespace mojo {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 template <>
 struct StructTraits<media::mojom::ColorPlaneLayoutDataView,
                     media::ColorPlaneLayout> {
