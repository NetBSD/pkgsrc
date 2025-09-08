$NetBSD: patch-ash_display_mirror__window__controller.cc,v 1.6 2025/09/08 13:13:46 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ash/display/mirror_window_controller.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ ash/display/mirror_window_controller.cc
@@ -283,7 +283,11 @@ void MirrorWindowController::UpdateWindo
       if (!base::Contains(display_info_list, iter->first,
                           &display::ManagedDisplayInfo::id)) {
         CloseAndDeleteHost(iter->second, true);
+#if defined(__llvm__)
+        mirroring_host_info_map_.erase(iter++);
+#else
         iter = mirroring_host_info_map_.erase(iter);
+#endif
       } else {
         ++iter;
       }
