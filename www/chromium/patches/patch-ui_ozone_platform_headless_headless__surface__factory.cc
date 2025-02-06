$NetBSD: patch-ui_ozone_platform_headless_headless__surface__factory.cc,v 1.1 2025/02/06 09:58:33 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/headless/headless_surface_factory.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/ozone/platform/headless/headless_surface_factory.cc
@@ -34,7 +34,7 @@
 #include "ui/ozone/platform/headless/headless_window_manager.h"
 #include "ui/ozone/public/surface_ozone_canvas.h"
 
-#if BUILDFLAG(ENABLE_VULKAN) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA))
+#if BUILDFLAG(ENABLE_VULKAN) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD))
 #include "ui/ozone/platform/headless/vulkan_implementation_headless.h"
 #endif
 
@@ -280,7 +280,7 @@ std::unique_ptr<gpu::VulkanImplementatio
 HeadlessSurfaceFactory::CreateVulkanImplementation(
     bool use_swiftshader,
     bool allow_protected_memory) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   return std::make_unique<VulkanImplementationHeadless>(use_swiftshader);
 #else
   return nullptr;
