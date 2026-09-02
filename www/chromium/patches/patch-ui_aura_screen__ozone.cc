$NetBSD: patch-ui_aura_screen__ozone.cc,v 1.25 2026/09/02 13:13:38 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/aura/screen_ozone.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ ui/aura/screen_ozone.cc
@@ -107,7 +107,7 @@ display::Display ScreenOzone::GetPrimary
   return platform_screen_->GetPrimaryDisplay();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 ScreenOzone::ScreenSaverSuspenderOzone::ScreenSaverSuspenderOzone(
     std::unique_ptr<ui::PlatformScreen::PlatformScreenSaverSuspender> suspender)
     : suspender_(std::move(suspender)) {}
