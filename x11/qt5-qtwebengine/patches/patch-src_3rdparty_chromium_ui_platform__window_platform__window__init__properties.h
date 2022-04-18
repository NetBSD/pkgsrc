$NetBSD: patch-src_3rdparty_chromium_ui_platform__window_platform__window__init__properties.h,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/ui/platform_window/platform_window_init_properties.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/ui/platform_window/platform_window_init_properties.h
@@ -41,7 +41,7 @@ enum class PlatformWindowOpacity {
 
 class WorkspaceExtensionDelegate;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 class X11ExtensionDelegate;
 #endif
 
@@ -82,7 +82,7 @@ struct COMPONENT_EXPORT(PLATFORM_WINDOW)
 
   WorkspaceExtensionDelegate* workspace_extension_delegate = nullptr;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   bool prefer_dark_theme = false;
   gfx::ImageSkia* icon = nullptr;
   base::Optional<int> background_color;
