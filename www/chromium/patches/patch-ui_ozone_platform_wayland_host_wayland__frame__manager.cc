$NetBSD: patch-ui_ozone_platform_wayland_host_wayland__frame__manager.cc,v 1.18 2026/05/10 15:30:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/wayland/host/wayland_frame_manager.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ ui/ozone/platform/wayland/host/wayland_frame_manager.cc
@@ -5,7 +5,9 @@
 #include "ui/ozone/platform/wayland/host/wayland_frame_manager.h"
 
 #include <presentation-time-client-protocol.h>
+#if !BUILDFLAG(IS_BSD)
 #include <sync/sync.h>
+#endif
 
 #include <cstdint>
 #include <variant>
@@ -463,8 +465,10 @@ std::optional<bool> WaylandFrameManager:
   surface->UpdateBufferDamageRegion(
       gfx::ToEnclosingRectIgnoringError(surface_damage));
 
+#if !BUILDFLAG(IS_BSD)
   if (!config.access_fence_handle.is_null())
     surface->set_acquire_fence(std::move(config.access_fence_handle));
+#endif
 
   bool needs_commit = false;
 
@@ -496,6 +500,9 @@ std::optional<bool> WaylandFrameManager:
       case WaylandBufferHandle::SyncMethod::kNone:
         break;
       case WaylandBufferHandle::SyncMethod::kSyncobj:
+#if BUILDFLAG(IS_BSD)
+        LOG(WARNING) << "WaylandBufferHandle::SyncMethod::kSyncobj is not supported!";
+#endif
         surface->RequestExplicitRelease(
             base::BindOnce(&WaylandFrameManager::OnExplicitBufferRelease,
                            weak_factory_.GetWeakPtr(), surface));
@@ -503,6 +510,9 @@ std::optional<bool> WaylandFrameManager:
       case WaylandBufferHandle::SyncMethod::kDMAFence:
         [[fallthrough]];
       case WaylandBufferHandle::SyncMethod::kImplicit:
+#if BUILDFLAG(IS_BSD)
+        LOG(WARNING) << "WaylandBufferHandle::SyncMethod::kSyncobj is not supported!";
+#endif
         buffer_handle->set_buffer_released_callback(
             base::BindOnce(&WaylandFrameManager::OnWlBufferRelease,
                            weak_factory_.GetWeakPtr(), surface),
@@ -737,8 +747,10 @@ void WaylandFrameManager::OnExplicitBuff
 
       if (fence.is_valid()) {
         if (frame->merged_release_fence_fd.is_valid()) {
+#if !BUILDFLAG(IS_BSD)
           frame->merged_release_fence_fd.reset(sync_merge(
               "", frame->merged_release_fence_fd.get(), fence.get()));
+#endif
         } else {
           frame->merged_release_fence_fd = std::move(fence);
         }
@@ -776,8 +788,10 @@ void WaylandFrameManager::OnWlBufferRele
 
         if (fence.is_valid()) {
           if (frame->merged_release_fence_fd.is_valid()) {
+#if !BUILDFLAG(IS_BSD)
             frame->merged_release_fence_fd.reset(sync_merge(
                 "", frame->merged_release_fence_fd.get(), fence.get()));
+#endif
           } else {
             frame->merged_release_fence_fd = std::move(fence);
           }
