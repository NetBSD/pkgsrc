$NetBSD: patch-ui_ozone_platform_wayland_common_wayland__util.cc,v 1.25 2026/09/02 13:13:39 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/wayland/common/wayland_util.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ ui/ozone/platform/wayland/common/wayland_util.cc
@@ -417,6 +417,7 @@ void RecordConnectionMetrics(wl_display*
         {"weston", WaylandCompositor::kWeston},
     };
 
+#if !BUILDFLAG(IS_BSD)
     const int fd = wl_display_get_fd(display);
     if (fd == -1) {
       return WaylandCompositor::kUnknown;
@@ -442,6 +443,7 @@ void RecordConnectionMetrics(wl_display*
         return compositor;
       }
     }
+#endif
 
     return WaylandCompositor::kOther;
   };
