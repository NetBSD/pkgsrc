$NetBSD: patch-components_password__manager_core_browser_password__manual__fallback__flow.cc,v 1.1 2025/02/06 09:58:01 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/password_manual_fallback_flow.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ components/password_manager/core/browser/password_manual_fallback_flow.cc
@@ -43,7 +43,7 @@ std::u16string GetUsernameFromLabel(cons
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Returns the password form corresponding to the `payload` data. In most
 // cases there is only one such form stored, but having more than one or no
 // forms is also possible. If there is more than one form, showing any of them
@@ -281,7 +281,7 @@ void PasswordManualFallbackFlow::DidAcce
     }
     case autofill::SuggestionType::kViewPasswordDetails: {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       std::optional<password_manager::PasswordForm> credentials =
           GetCorrespondingPasswordForm(
               suggestion.GetPayload<Suggestion::PasswordSuggestionDetails>(),
@@ -418,7 +418,7 @@ void PasswordManualFallbackFlow::EnsureC
     const Suggestion::PasswordSuggestionDetails& payload,
     base::OnceClosure on_allowed) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (payload.is_cross_domain) {
     cross_domain_confirmation_popup_controller_ =
         password_client_->ShowCrossDomainConfirmationPopup(
