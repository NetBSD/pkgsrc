$NetBSD: patch-ui_ozone_platform_wayland_host_wayland__toplevel__window.h,v 1.1 2025/02/06 09:58:34 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/wayland/host/wayland_toplevel_window.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/ozone/platform/wayland/host/wayland_toplevel_window.h
@@ -262,7 +262,7 @@ class WaylandToplevelWindow : public Way
   // The display ID to switch to in case the state is `kFullscreen`.
   int64_t fullscreen_display_id_ = display::kInvalidDisplayId;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Contains the current state of the tiled edges.
   WindowTiledEdges tiled_state_;
 #endif
