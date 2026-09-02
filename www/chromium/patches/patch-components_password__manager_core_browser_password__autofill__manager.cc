$NetBSD: patch-components_password__manager_core_browser_password__autofill__manager.cc,v 1.21 2026/09/02 13:13:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/password_autofill_manager.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ components/password_manager/core/browser/password_autofill_manager.cc
@@ -403,7 +403,7 @@ void PasswordAutofillManager::DidAcceptS
                          weak_ptr_factory_.GetWeakPtr(), payload);
       if (payload.is_cross_domain) {
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
         cross_domain_confirmation_controller_ =
             password_client_->ShowCrossDomainConfirmationPopup(
                 last_popup_open_args_.element_bounds,
@@ -454,7 +454,7 @@ void PasswordAutofillManager::DidAcceptS
                          weak_ptr_factory_.GetWeakPtr(), *password_credential);
       if (password_credential->is_grouped_affiliation) {
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
         cross_domain_confirmation_controller_ =
             password_client_->ShowCrossDomainConfirmationPopup(
                 last_popup_open_args_.element_bounds,
@@ -723,7 +723,7 @@ void PasswordAutofillManager::DidNavigat
   manual_fallback_metrics_recorder_ =
       std::make_unique<PasswordManualFallbackMetricsRecorder>();
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   cross_domain_confirmation_controller_.reset();
 #endif
   wait_for_passkeys_timer_.Stop();
