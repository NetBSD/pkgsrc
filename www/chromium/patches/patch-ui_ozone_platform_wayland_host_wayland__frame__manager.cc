$NetBSD: patch-ui_ozone_platform_wayland_host_wayland__frame__manager.cc,v 1.4 2025/08/13 07:44:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/wayland/host/wayland_frame_manager.cc.orig	2025-07-29 22:51:44.000000000 +0000
+++ ui/ozone/platform/wayland/host/wayland_frame_manager.cc
@@ -461,8 +461,10 @@ std::optional<bool> WaylandFrameManager:
   surface->UpdateBufferDamageRegion(
       gfx::ToEnclosingRectIgnoringError(surface_damage));
 
+#if !BUILDFLAG(IS_BSD)
   if (!config.access_fence_handle.is_null())
     surface->set_acquire_fence(std::move(config.access_fence_handle));
+#endif
 
   bool needs_commit = false;
 
