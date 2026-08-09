$NetBSD: patch-chrome_browser_ui_webui_password__manager_promo__cards__handler.h,v 1.14 2026/08/09 06:31:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/password_manager/promo_cards_handler.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/ui/webui/password_manager/promo_cards_handler.h
@@ -54,7 +54,7 @@ class PromoCardsHandler : public content
 
   PasswordPromoCardBase* GetPromoToShowAndUpdatePref();
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnEncryptorReceived(base::Value callback_id,
                            scoped_refptr<os_crypt_async::Encryptor> encryptor);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -62,7 +62,7 @@ class PromoCardsHandler : public content
   raw_ptr<Profile> profile_;
 
   std::vector<std::unique_ptr<PasswordPromoCardBase>> promo_cards_;
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // This points into `promo_cards_`, so should be ordered after it.
   raw_ptr<RelaunchChromePromo> relaunch_chrome_promo_ = nullptr;
 
