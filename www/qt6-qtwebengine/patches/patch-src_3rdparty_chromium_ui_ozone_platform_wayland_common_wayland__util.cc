$NetBSD: patch-src_3rdparty_chromium_ui_ozone_platform_wayland_common_wayland__util.cc,v 1.1 2026/04/30 06:39:45 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/ozone/platform/wayland/common/wayland_util.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/ui/ozone/platform/wayland/common/wayland_util.cc
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
