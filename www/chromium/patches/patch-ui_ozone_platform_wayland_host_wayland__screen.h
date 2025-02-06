$NetBSD: patch-ui_ozone_platform_wayland_host_wayland__screen.h,v 1.1 2025/02/06 09:58:34 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/wayland/host/wayland_screen.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/ozone/platform/wayland/host/wayland_screen.h
@@ -23,7 +23,7 @@
 #include "ui/ozone/platform/wayland/host/wayland_output.h"
 #include "ui/ozone/public/platform_screen.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/scoped_observation.h"
 #include "ui/linux/device_scale_factor_observer.h"
 #include "ui/linux/linux_ui.h"
@@ -43,7 +43,7 @@ class OrgGnomeMutterIdleMonitor;
 
 // A PlatformScreen implementation for Wayland.
 class WaylandScreen : public PlatformScreen
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     ,
                       public DeviceScaleFactorObserver
 #endif
@@ -95,7 +95,7 @@ class WaylandScreen : public PlatformScr
   display::TabletState GetTabletState() const override;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // DeviceScaleFactorObserver:
   void OnDeviceScaleFactorChanged() override;
 #endif
@@ -155,7 +155,7 @@ class WaylandScreen : public PlatformScr
   display::TabletState tablet_state_;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::ScopedObservation<ui::LinuxUi, DeviceScaleFactorObserver>
       display_scale_factor_observer_{this};
 #endif
