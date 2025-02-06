$NetBSD: patch-ui_ozone_platform_wayland_host_wayland__screen.cc,v 1.1 2025/02/06 09:58:34 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/wayland/host/wayland_screen.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/ozone/platform/wayland/host/wayland_screen.cc
@@ -47,7 +47,7 @@
 #include "ui/ozone/platform/wayland/host/org_gnome_mutter_idle_monitor.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/base/ui_base_features.h"
 #include "ui/linux/linux_ui.h"
 #endif
@@ -135,7 +135,7 @@ WaylandScreen::WaylandScreen(WaylandConn
   tablet_state_ = connection_->GetTabletState();
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (connection_->IsUiScaleEnabled() && LinuxUi::instance()) {
     OnDeviceScaleFactorChanged();
     display_scale_factor_observer_.Observe(LinuxUi::instance());
@@ -614,7 +614,7 @@ bool WaylandScreen::VerifyOutputStateCon
   return true;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void WaylandScreen::OnDeviceScaleFactorChanged() {
   CHECK(connection_->IsUiScaleEnabled());
   CHECK(LinuxUi::instance());
