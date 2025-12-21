$NetBSD: patch-src_3rdparty_chromium_media_mojo_mojom_video__frame__mojom__traits.cc,v 1.1 2025/12/21 09:38:33 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/media/mojo/mojom/video_frame_mojom_traits.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/media/mojo/mojom/video_frame_mojom_traits.cc
@@ -22,7 +22,7 @@
 #include "ui/gfx/mojom/color_space_mojom_traits.h"
 #include "ui/gfx/mojom/hdr_metadata_mojom_traits.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/posix/eintr_wrapper.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
