$NetBSD: patch-chrome_browser_ui_webui_password__manager_notification__cards__handler.h,v 1.2 2026/09/22 13:41:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/password_manager/notification_cards_handler.h.orig	2026-09-14 22:17:16.000000000 +0000
+++ chrome/browser/ui/webui/password_manager/notification_cards_handler.h
@@ -56,7 +56,7 @@ class NotificationCardsHandler : public 
 
   PasswordNotificationCardBase* GetNotificationCardToShowAndUpdatePref();
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnEncryptorReceived(base::Value callback_id,
                            scoped_refptr<os_crypt_async::Encryptor> encryptor);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -65,7 +65,7 @@ class NotificationCardsHandler : public 
 
   std::vector<std::unique_ptr<PasswordNotificationCardBase>>
       notification_cards_;
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // This points into `notification_cards_`, so should be ordered after it.
   raw_ptr<RelaunchChromeBanner> relaunch_chrome_banner_ = nullptr;
 
