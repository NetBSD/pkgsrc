$NetBSD: patch-media_gpu_chromeos_platform__video__frame__utils.cc,v 1.19 2026/05/10 15:30:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/chromeos/platform_video_frame_utils.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ media/gpu/chromeos/platform_video_frame_utils.cc
@@ -69,7 +69,7 @@ static std::unique_ptr<ui::GbmDevice> Cr
     const base::FilePath dev_path(FILE_PATH_LITERAL(
         base::StrCat({drm_node_file_prefix, base::NumberToString(i)})));
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_V4L2_CODEC)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_V4L2_CODEC)
     const bool is_render_node = drm_node_file_prefix.contains("render");
 
     // TODO(b/313513760): don't guard base::File::FLAG_WRITE behind
@@ -179,7 +179,7 @@ class GbmDeviceWrapper {
             switches::kRenderNodeOverride)});
     for (const auto& dev_path : dev_paths) {
       if (!dev_path.empty()) {
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_V4L2_CODEC)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_V4L2_CODEC)
         const bool is_render_node = dev_path.value().contains("render");
 
         // TODO(b/313513760): don't guard base::File::FLAG_WRITE behind
