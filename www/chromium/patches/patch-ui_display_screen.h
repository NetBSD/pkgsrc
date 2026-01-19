$NetBSD: patch-ui_display_screen.h,v 1.14 2026/01/19 16:14:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/display/screen.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ ui/display/screen.h
@@ -139,7 +139,7 @@ class DISPLAY_EXPORT Screen {
   // (both of which may or may not be `nearest_id`).
   display::ScreenInfos GetScreenInfosNearestDisplay(int64_t nearest_id) const;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Object which suspends the platform-specific screensaver for the duration of
   // its existence.
   class ScreenSaverSuspender {
@@ -245,7 +245,7 @@ class DISPLAY_EXPORT Screen {
   int64_t display_id_for_new_windows_;
   int64_t scoped_display_id_for_new_windows_ = display::kInvalidDisplayId;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   uint32_t screen_saver_suspension_count_ = 0;
 #endif  // BUILDFLAG(IS_LINUX)
 };
