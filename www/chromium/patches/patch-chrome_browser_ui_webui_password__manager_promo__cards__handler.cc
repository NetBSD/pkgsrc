$NetBSD: patch-chrome_browser_ui_webui_password__manager_promo__cards__handler.cc,v 1.7 2025/09/12 16:02:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/password_manager/promo_cards_handler.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ chrome/browser/ui/webui/password_manager/promo_cards_handler.cc
@@ -28,7 +28,7 @@
 #include "chrome/browser/ui/webui/password_manager/promo_cards/web_password_manager_promo.h"
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/password_manager/promo_cards/relaunch_chrome_promo.h"
 #endif
 
@@ -71,7 +71,7 @@ std::vector<std::unique_ptr<PasswordProm
           .get()));
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   promo_cards.push_back(
       std::make_unique<RelaunchChromePromo>(profile->GetPrefs()));
 #endif
