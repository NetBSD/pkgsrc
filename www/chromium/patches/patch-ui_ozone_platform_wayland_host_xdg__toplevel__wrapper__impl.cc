$NetBSD: patch-ui_ozone_platform_wayland_host_xdg__toplevel__wrapper__impl.cc,v 1.1 2025/02/06 09:58:34 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/wayland/host/xdg_toplevel_wrapper_impl.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/ozone/platform/wayland/host/xdg_toplevel_wrapper_impl.cc
@@ -322,7 +322,7 @@ void XDGToplevelWrapperImpl::OnToplevelC
   window_states.is_activated =
       CheckIfWlArrayHasValue(states, XDG_TOPLEVEL_STATE_ACTIVATED);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (xdg_toplevel_get_version(toplevel) >=
       XDG_TOPLEVEL_STATE_TILED_LEFT_SINCE_VERSION) {
     // All four tiled states have the same since version, so it is enough to
