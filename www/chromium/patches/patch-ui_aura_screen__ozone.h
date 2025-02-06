$NetBSD: patch-ui_aura_screen__ozone.h,v 1.1 2025/02/06 09:58:30 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/aura/screen_ozone.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/aura/screen_ozone.h
@@ -45,7 +45,7 @@ class AURA_EXPORT ScreenOzone : public d
   display::Display GetDisplayMatching(
       const gfx::Rect& match_rect) const override;
   display::Display GetPrimaryDisplay() const override;
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<display::Screen::ScreenSaverSuspender> SuspendScreenSaver()
       override;
 #endif  // BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
@@ -74,7 +74,7 @@ class AURA_EXPORT ScreenOzone : public d
   ui::PlatformScreen* platform_screen() { return platform_screen_.get(); }
 
  private:
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   class ScreenSaverSuspenderOzone
       : public display::Screen::ScreenSaverSuspender {
    public:
