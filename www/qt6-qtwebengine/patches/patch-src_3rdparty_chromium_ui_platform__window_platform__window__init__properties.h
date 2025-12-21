$NetBSD: patch-src_3rdparty_chromium_ui_platform__window_platform__window__init__properties.h,v 1.1 2025/12/21 09:38:49 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/platform_window/platform_window_init_properties.h.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/ui/platform_window/platform_window_init_properties.h
@@ -56,7 +56,7 @@ class WorkspaceExtensionDelegate;
 class ScenicWindowDelegate;
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 class X11ExtensionDelegate;
 #endif
 
@@ -121,7 +121,7 @@ struct COMPONENT_EXPORT(PLATFORM_WINDOW)
 
   PlatformWindowShadowType shadow_type = PlatformWindowShadowType::kDefault;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool prefer_dark_theme = false;
   raw_ptr<gfx::ImageSkia> icon = nullptr;
   std::optional<SkColor> background_color;
