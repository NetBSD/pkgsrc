$NetBSD: patch-gpu_command__buffer_service_shared__image_angle__vulkan__image__backing__factory.cc,v 1.1 2025/02/06 09:58:09 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/service/shared_image/angle_vulkan_image_backing_factory.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ gpu/command_buffer/service/shared_image/angle_vulkan_image_backing_factory.cc
@@ -20,7 +20,7 @@ namespace {
 // TODO(penghuang): verify the scanout is the right usage for video playback.
 // crbug.com/1280798
 constexpr SharedImageUsageSet kSupportedUsage =
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     SHARED_IMAGE_USAGE_SCANOUT |
 #endif
     SHARED_IMAGE_USAGE_GLES2_READ | SHARED_IMAGE_USAGE_GLES2_WRITE |
