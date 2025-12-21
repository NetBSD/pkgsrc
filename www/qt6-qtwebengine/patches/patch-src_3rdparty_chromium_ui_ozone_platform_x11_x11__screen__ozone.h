$NetBSD: patch-src_3rdparty_chromium_ui_ozone_platform_x11_x11__screen__ozone.h,v 1.1 2025/12/21 09:38:49 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/ozone/platform/x11/x11_screen_ozone.h.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/ui/ozone/platform/x11/x11_screen_ozone.h
@@ -102,7 +102,7 @@ class X11ScreenOzone : public PlatformSc
   // Indicates that |this| is initialized.
   bool initialized_ = false;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::ScopedObservation<ui::LinuxUi, DeviceScaleFactorObserver>
       display_scale_factor_observer_{this};
 #endif
