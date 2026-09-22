$NetBSD: patch-chrome_browser_ui_webui_password__manager_notification__cards_relaunch__chrome__banner.cc,v 1.2 2026/09/22 13:41:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/password_manager/notification_cards/relaunch_chrome_banner.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ chrome/browser/ui/webui/password_manager/notification_cards/relaunch_chrome_banner.cc
@@ -46,7 +46,7 @@ std::u16string RelaunchChromeBanner::Get
   return l10n_util::GetStringUTF16(
 #if BUILDFLAG(IS_MAC)
       IDS_PASSWORD_MANAGER_UI_RELAUNCH_CHROME_PROMO_CARD_TITLE
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       IDS_PASSWORD_MANAGER_UI_RELAUNCH_CHROME_PROMO_CARD_TITLE_LINUX
 #endif
   );
@@ -56,7 +56,7 @@ std::u16string RelaunchChromeBanner::Get
   return l10n_util::GetStringUTF16(
 #if BUILDFLAG(IS_MAC)
       IDS_PASSWORD_MANAGER_UI_RELAUNCH_CHROME_PROMO_CARD_DESCRIPTION
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       IDS_PASSWORD_MANAGER_UI_RELAUNCH_CHROME_PROMO_CARD_DESCRIPTION_LINUX
 #endif
   );
