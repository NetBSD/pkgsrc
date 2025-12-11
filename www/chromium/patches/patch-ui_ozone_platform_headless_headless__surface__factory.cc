$NetBSD: patch-ui_ozone_platform_headless_headless__surface__factory.cc,v 1.11 2025/12/11 09:13:48 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/headless/headless_surface_factory.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ ui/ozone/platform/headless/headless_surface_factory.cc
@@ -35,7 +35,7 @@
 #include "ui/ozone/platform/headless/headless_window_manager.h"
 #include "ui/ozone/public/surface_ozone_canvas.h"
 
-#if BUILDFLAG(ENABLE_VULKAN) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA))
+#if BUILDFLAG(ENABLE_VULKAN) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD))
 #include "ui/ozone/platform/headless/vulkan_implementation_headless.h"
 #endif
 
@@ -285,7 +285,7 @@ std::unique_ptr<gpu::VulkanImplementatio
 HeadlessSurfaceFactory::CreateVulkanImplementation(
     bool use_swiftshader,
     bool allow_protected_memory) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   return std::make_unique<VulkanImplementationHeadless>(use_swiftshader);
 #else
   return nullptr;
