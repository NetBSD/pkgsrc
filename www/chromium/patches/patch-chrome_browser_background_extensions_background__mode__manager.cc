$NetBSD: patch-chrome_browser_background_extensions_background__mode__manager.cc,v 1.19 2026/06/01 10:09:05 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/background/extensions/background_mode_manager.cc.orig	2026-05-26 20:39:02.000000000 +0000
+++ chrome/browser/background/extensions/background_mode_manager.cc
@@ -870,7 +870,7 @@ gfx::ImageSkia GetStatusTrayIcon() {
   }
 
   return family->CreateExact(size).AsImageSkia();
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return *ui::ResourceBundle::GetSharedInstance().GetImageSkiaNamed(
       IDR_PRODUCT_LOGO_128);
 #elif BUILDFLAG(IS_MAC)
