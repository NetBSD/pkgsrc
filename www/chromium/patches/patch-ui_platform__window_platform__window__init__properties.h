$NetBSD: patch-ui_platform__window_platform__window__init__properties.h,v 1.14 2026/01/19 16:14:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/platform_window/platform_window_init_properties.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ ui/platform_window/platform_window_init_properties.h
@@ -56,7 +56,7 @@ class WorkspaceExtensionDelegate;
 class ScenicWindowDelegate;
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 class X11ExtensionDelegate;
 #endif
 
@@ -120,7 +120,7 @@ struct COMPONENT_EXPORT(PLATFORM_WINDOW)
 
   PlatformWindowShadowType shadow_type = PlatformWindowShadowType::kDefault;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool prefer_dark_theme = false;
   raw_ptr<gfx::ImageSkia> icon = nullptr;
   std::optional<SkColor> background_color;
