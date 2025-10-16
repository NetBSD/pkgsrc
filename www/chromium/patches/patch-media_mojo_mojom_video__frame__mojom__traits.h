$NetBSD: patch-media_mojo_mojom_video__frame__mojom__traits.h,v 1.7 2025/10/16 19:43:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/mojo/mojom/video_frame_mojom_traits.h.orig	2025-10-13 21:41:26.000000000 +0000
+++ media/mojo/mojom/video_frame_mojom_traits.h
@@ -21,7 +21,7 @@
 
 namespace mojo {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 template <>
 struct StructTraits<media::mojom::ColorPlaneLayoutDataView,
                     media::ColorPlaneLayout> {
