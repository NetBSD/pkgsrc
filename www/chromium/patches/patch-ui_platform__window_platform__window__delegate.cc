$NetBSD: patch-ui_platform__window_platform__window__delegate.cc,v 1.2 2025/05/16 16:08:35 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/platform_window/platform_window_delegate.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ ui/platform_window/platform_window_delegate.cc
@@ -56,7 +56,7 @@ gfx::Insets PlatformWindowDelegate::Calc
   return gfx::Insets();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void PlatformWindowDelegate::OnWindowTiledStateChanged(
     WindowTiledEdges new_tiled_edges) {}
 #endif
