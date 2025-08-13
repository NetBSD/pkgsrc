$NetBSD: patch-components_password__manager_core_browser_password__autofill__manager.cc,v 1.1 2025/08/13 07:44:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/password_autofill_manager.cc.orig	2025-07-29 22:51:44.000000000 +0000
+++ components/password_manager/core/browser/password_autofill_manager.cc
@@ -288,7 +288,7 @@ void PasswordAutofillManager::DidAcceptS
       }
       if (password_credential->is_grouped_affiliation) {
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
         cross_domain_confirmation_controller_ =
             password_client_->ShowCrossDomainConfirmationPopup(
                 last_popup_open_args_.element_bounds,
@@ -525,7 +525,7 @@ void PasswordAutofillManager::DidNavigat
   manual_fallback_metrics_recorder_ =
       std::make_unique<PasswordManualFallbackMetricsRecorder>();
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   cross_domain_confirmation_controller_.reset();
 #endif
   wait_for_passkeys_timer_.Stop();
