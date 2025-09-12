$NetBSD: patch-gpu_command__buffer_service_shared__image_external__vk__image__backing__factory.cc,v 1.7 2025/09/12 16:02:30 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.cc
@@ -140,7 +140,7 @@ bool IsFormatSupported(viz::SharedImageF
 
 SharedImageUsageSet SupportedUsage() {
   SharedImageUsageSet supported_usage =
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DAWN)
       SHARED_IMAGE_USAGE_WEBGPU_READ | SHARED_IMAGE_USAGE_WEBGPU_WRITE |
       SHARED_IMAGE_USAGE_WEBGPU_SWAP_CHAIN_TEXTURE |
       SHARED_IMAGE_USAGE_WEBGPU_STORAGE_TEXTURE |
