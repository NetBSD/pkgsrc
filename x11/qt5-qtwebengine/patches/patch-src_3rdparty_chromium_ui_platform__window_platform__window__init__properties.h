$NetBSD: patch-src_3rdparty_chromium_ui_platform__window_platform__window__init__properties.h,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/ui/platform_window/platform_window_init_properties.h.orig	2020-07-15 18:56:34.000000000 +0000
+++ src/3rdparty/chromium/ui/platform_window/platform_window_init_properties.h
@@ -41,7 +41,7 @@ enum class PlatformWindowOpacity {
 
 class WorkspaceExtensionDelegate;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 class X11ExtensionDelegate;
 #endif
 
@@ -82,7 +82,7 @@ struct COMPONENT_EXPORT(PLATFORM_WINDOW)
 
   WorkspaceExtensionDelegate* workspace_extension_delegate = nullptr;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   bool prefer_dark_theme = false;
   gfx::ImageSkia* icon = nullptr;
   base::Optional<int> background_color;
