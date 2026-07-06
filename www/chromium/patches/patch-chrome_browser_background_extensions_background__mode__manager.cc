$NetBSD: patch-chrome_browser_background_extensions_background__mode__manager.cc,v 1.21 2026/07/06 13:06:42 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/background/extensions/background_mode_manager.cc.orig	2026-06-23 23:37:18.000000000 +0000
+++ chrome/browser/background/extensions/background_mode_manager.cc
@@ -871,7 +871,7 @@ gfx::ImageSkia GetStatusTrayIcon() {
   }
 
   return family->CreateExact(size).AsImageSkia();
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return *ui::ResourceBundle::GetSharedInstance().GetImageSkiaNamed(
       IDR_PRODUCT_LOGO_128);
 #elif BUILDFLAG(IS_MAC)
