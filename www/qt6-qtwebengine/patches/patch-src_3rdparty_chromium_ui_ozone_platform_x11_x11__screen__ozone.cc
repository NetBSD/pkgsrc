$NetBSD: patch-src_3rdparty_chromium_ui_ozone_platform_x11_x11__screen__ozone.cc,v 1.1 2025/12/21 09:38:49 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/ozone/platform/x11/x11_screen_ozone.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/ui/ozone/platform/x11/x11_screen_ozone.cc
@@ -22,7 +22,7 @@
 #include "ui/ozone/platform/x11/x11_window.h"
 #include "ui/ozone/platform/x11/x11_window_manager.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -77,7 +77,7 @@ X11ScreenOzone::X11ScreenOzone()
       window_manager_(X11WindowManager::GetInstance()),
       x11_display_manager_(std::make_unique<XDisplayManager>(this)) {
   DCHECK(window_manager_);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* linux_ui = ui::LinuxUi::instance()) {
     display_scale_factor_observer_.Observe(linux_ui);
   }
