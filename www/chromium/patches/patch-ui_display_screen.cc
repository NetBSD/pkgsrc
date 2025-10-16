$NetBSD: patch-ui_display_screen.cc,v 1.8 2025/10/16 19:43:37 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/display/screen.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ ui/display/screen.cc
@@ -87,7 +87,7 @@ void Screen::SetDisplayForNewWindows(int
   display_id_for_new_windows_ = display_id;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 Screen::ScreenSaverSuspender::~ScreenSaverSuspender() = default;
 
 std::unique_ptr<Screen::ScreenSaverSuspender> Screen::SuspendScreenSaver() {
