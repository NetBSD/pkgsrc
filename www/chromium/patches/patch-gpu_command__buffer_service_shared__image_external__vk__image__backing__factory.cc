$NetBSD: patch-gpu_command__buffer_service_shared__image_external__vk__image__backing__factory.cc,v 1.22 2026/07/06 13:06:52 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.cc.orig	2026-06-23 23:37:18.000000000 +0000
+++ gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.cc
@@ -152,7 +152,7 @@ bool IsFormatSupported(viz::SharedImageF
 
 SharedImageUsageSet SupportedUsage() {
   SharedImageUsageSet supported_usage =
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DAWN)
       SHARED_IMAGE_USAGE_WEBGPU_READ | SHARED_IMAGE_USAGE_WEBGPU_WRITE |
       SHARED_IMAGE_USAGE_WEBGPU_SWAP_CHAIN_TEXTURE |
       SHARED_IMAGE_USAGE_WEBGPU_STORAGE_TEXTURE |
