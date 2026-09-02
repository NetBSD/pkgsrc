$NetBSD: patch-media_gpu_v4l2_v4l2__utils.cc,v 1.17 2026/09/02 13:13:33 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/v4l2/v4l2_utils.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ media/gpu/v4l2/v4l2_utils.cc
@@ -15,7 +15,7 @@
 
 #include "base/compiler_specific.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <drm_fourcc.h>
 #endif
 
@@ -240,7 +240,7 @@ std::optional<VideoFrameLayout> V4L2Form
   }
   const VideoPixelFormat video_format = video_fourcc->ToVideoPixelFormat();
   uint64_t modifiers = gfx::NativePixmapHandle::kNoModifier;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (video_fourcc == Fourcc(Fourcc::MM21)) {
     modifiers = DRM_FORMAT_MOD_MTK_16L_32S_TILE;
   } else {
