$NetBSD: patch-ui_display_screen.cc,v 1.13 2025/12/23 13:22:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/display/screen.cc.orig	2025-12-17 23:05:18.000000000 +0000
+++ ui/display/screen.cc
@@ -82,7 +82,7 @@ void Screen::SetDisplayForNewWindows(int
   display_id_for_new_windows_ = display_id;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 Screen::ScreenSaverSuspender::~ScreenSaverSuspender() = default;
 
 std::unique_ptr<Screen::ScreenSaverSuspender> Screen::SuspendScreenSaver() {
