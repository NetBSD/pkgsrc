$NetBSD: patch-device_vr_openxr_openxr__swapchain__info.cc,v 1.3 2026/10/13 13:16:42 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- device/vr/openxr/openxr_swapchain_info.cc.orig	2026-10-06 00:06:58.000000000 +0000
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
