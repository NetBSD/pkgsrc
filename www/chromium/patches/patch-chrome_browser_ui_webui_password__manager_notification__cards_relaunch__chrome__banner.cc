$NetBSD: patch-chrome_browser_ui_webui_password__manager_notification__cards_relaunch__chrome__banner.cc,v 1.1 2026/09/02 13:13:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/password_manager/notification_cards/relaunch_chrome_banner.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/ui/webui/password_manager/notification_cards/relaunch_chrome_banner.cc
@@ -37,7 +37,7 @@ std::u16string RelaunchChromeBanner::Get
   return l10n_util::GetStringUTF16(
 #if BUILDFLAG(IS_MAC)
       IDS_PASSWORD_MANAGER_UI_RELAUNCH_CHROME_PROMO_CARD_TITLE
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       IDS_PASSWORD_MANAGER_UI_RELAUNCH_CHROME_PROMO_CARD_TITLE_LINUX
 #endif
   );
@@ -47,7 +47,7 @@ std::u16string RelaunchChromeBanner::Get
   return l10n_util::GetStringUTF16(
 #if BUILDFLAG(IS_MAC)
       IDS_PASSWORD_MANAGER_UI_RELAUNCH_CHROME_PROMO_CARD_DESCRIPTION
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       IDS_PASSWORD_MANAGER_UI_RELAUNCH_CHROME_PROMO_CARD_DESCRIPTION_LINUX
 #endif
   );
