$NetBSD: patch-ui_ozone_platform_headless_headless__surface__factory.cc,v 1.16 2026/03/14 12:40:45 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/headless/headless_surface_factory.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ ui/ozone/platform/headless/headless_surface_factory.cc
@@ -35,7 +35,7 @@
 #include "ui/ozone/platform/headless/headless_window_manager.h"
 #include "ui/ozone/public/surface_ozone_canvas.h"
 
-#if BUILDFLAG(ENABLE_VULKAN) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA))
+#if BUILDFLAG(ENABLE_VULKAN) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD))
 #include "ui/ozone/platform/headless/vulkan_implementation_headless.h"
 #endif
 
@@ -282,7 +282,7 @@ std::unique_ptr<gpu::VulkanImplementatio
 HeadlessSurfaceFactory::CreateVulkanImplementation(
     bool use_swiftshader,
     bool allow_protected_memory) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   return std::make_unique<VulkanImplementationHeadless>(use_swiftshader);
 #else
   return nullptr;
