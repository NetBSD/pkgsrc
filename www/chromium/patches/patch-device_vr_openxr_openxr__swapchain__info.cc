$NetBSD: patch-device_vr_openxr_openxr__swapchain__info.cc,v 1.2 2026/10/02 11:43:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- device/vr/openxr/openxr_swapchain_info.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ device/vr/openxr/openxr_swapchain_info.cc
@@ -17,7 +17,7 @@ OpenXrSwapchainInfo::OpenXrSwapchainInfo
 #elif BUILDFLAG(IS_ANDROID)
 OpenXrSwapchainInfo::OpenXrSwapchainInfo(uint32_t texture)
     : openxr_texture(texture) {}
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 OpenXrSwapchainInfo::OpenXrSwapchainInfo(VkImage vk_image)
     : vk_image(vk_image) {}
 #endif
