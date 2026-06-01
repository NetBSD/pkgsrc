$NetBSD: patch-ui_platform__window_platform__window__delegate.h,v 1.20 2026/06/01 10:09:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/platform_window/platform_window_delegate.h.orig	2026-05-26 20:39:02.000000000 +0000
+++ ui/platform_window/platform_window_delegate.h
@@ -146,7 +146,7 @@ class COMPONENT_EXPORT(PLATFORM_WINDOW) 
   virtual void OnWindowStateChanged(PlatformWindowState old_state,
                                     PlatformWindowState new_state) = 0;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Notifies the delegate that the tiled state of the window edges has changed.
   virtual void OnWindowTiledStateChanged(WindowTiledEdges new_tiled_edges);
 #endif
