$NetBSD: patch-ui_base_x_x11__display__manager.cc,v 1.1 2025/02/06 09:58:31 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/x/x11_display_manager.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/base/x/x11_display_manager.cc
@@ -16,7 +16,7 @@
 #include "ui/gfx/x/randr.h"
 #include "ui/gfx/x/xproto.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -92,7 +92,7 @@ void XDisplayManager::FetchDisplayList()
           ? display::Display::GetForcedDeviceScaleFactor()
           : 1.0f};
   const auto* display_config = &empty_display_config;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (const auto* linux_ui = ui::LinuxUi::instance()) {
     display_config = &linux_ui->display_config();
   }
