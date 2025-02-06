$NetBSD: patch-ui_ozone_platform_wayland_host_wayland__toplevel__window.cc,v 1.1 2025/02/06 09:58:34 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/wayland/host/wayland_toplevel_window.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/ozone/platform/wayland/host/wayland_toplevel_window.cc
@@ -629,7 +629,7 @@ void WaylandToplevelWindow::HandleToplev
   const bool did_active_change = is_active_ != window_states.is_activated;
   is_active_ = window_states.is_activated;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The tiled state affects the window geometry, so apply it here.
   if (window_states.tiled_edges != tiled_state_) {
     // This configure changes the decoration insets.  We should adjust the
