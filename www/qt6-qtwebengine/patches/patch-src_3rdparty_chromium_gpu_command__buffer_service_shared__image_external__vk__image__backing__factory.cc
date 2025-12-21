$NetBSD: patch-src_3rdparty_chromium_gpu_command__buffer_service_shared__image_external__vk__image__backing__factory.cc,v 1.1 2025/12/21 09:38:30 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.cc.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/gpu/command_buffer/service/shared_image/external_vk_image_backing_factory.cc
@@ -168,7 +168,7 @@ bool IsFormatSupported(viz::SharedImageF
 
 SharedImageUsageSet SupportedUsage() {
   SharedImageUsageSet supported_usage =
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DAWN)
       SHARED_IMAGE_USAGE_WEBGPU_READ | SHARED_IMAGE_USAGE_WEBGPU_WRITE |
       SHARED_IMAGE_USAGE_WEBGPU_SWAP_CHAIN_TEXTURE |
       SHARED_IMAGE_USAGE_WEBGPU_STORAGE_TEXTURE |
