$NetBSD: patch-chrome_browser_background_extensions_background__mode__manager.cc,v 1.23 2026/08/09 06:31:07 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/background/extensions/background_mode_manager.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/background/extensions/background_mode_manager.cc
@@ -871,7 +871,7 @@ gfx::ImageSkia GetStatusTrayIcon() {
   }
 
   return family->CreateExact(size).AsImageSkia();
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return *ui::ResourceBundle::GetSharedInstance().GetImageSkiaNamed(
       IDR_PRODUCT_LOGO_128);
 #elif BUILDFLAG(IS_MAC)
