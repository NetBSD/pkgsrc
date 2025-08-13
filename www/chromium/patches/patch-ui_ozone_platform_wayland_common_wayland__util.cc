$NetBSD: patch-ui_ozone_platform_wayland_common_wayland__util.cc,v 1.5 2025/08/13 07:44:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/wayland/common/wayland_util.cc.orig	2025-07-29 22:51:44.000000000 +0000
+++ ui/ozone/platform/wayland/common/wayland_util.cc
@@ -421,6 +421,7 @@ void RecordConnectionMetrics(wl_display*
         {"weston", WaylandCompositor::kWeston},
     };
 
+#if !BUILDFLAG(IS_BSD)
     const int fd = wl_display_get_fd(display);
     if (fd == -1) {
       return WaylandCompositor::kUnknown;
@@ -446,6 +447,7 @@ void RecordConnectionMetrics(wl_display*
         return compositor;
       }
     }
+#endif
 
     return WaylandCompositor::kOther;
   };
