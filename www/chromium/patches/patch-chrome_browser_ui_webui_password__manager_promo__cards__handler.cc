$NetBSD: patch-chrome_browser_ui_webui_password__manager_promo__cards__handler.cc,v 1.1 2025/02/06 09:57:55 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/password_manager/promo_cards_handler.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/ui/webui/password_manager/promo_cards_handler.cc
@@ -28,7 +28,7 @@
 #include "chrome/browser/ui/webui/password_manager/promo_cards/web_password_manager_promo.h"
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/password_manager/promo_cards/relaunch_chrome_promo.h"
 #endif
 
@@ -81,7 +81,7 @@ std::vector<std::unique_ptr<PasswordProm
           .get()));
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   promo_cards.push_back(
       std::make_unique<RelaunchChromePromo>(profile->GetPrefs()));
 #endif
