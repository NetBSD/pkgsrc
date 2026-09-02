$NetBSD: patch-components_password__manager_core_browser_password__manual__fallback__flow.cc,v 1.25 2026/09/02 13:13:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/password_manual_fallback_flow.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ components/password_manager/core/browser/password_manual_fallback_flow.cc
@@ -52,7 +52,7 @@ std::u16string GetUsernameFromLabel(cons
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Returns the password form corresponding to the `payload` data. In most
 // cases there is only one such form stored, but having more than one or no
 // forms is also possible. If there is more than one form, showing any of them
@@ -350,7 +350,7 @@ void PasswordManualFallbackFlow::DidAcce
     }
     case autofill::SuggestionType::kViewPasswordDetails: {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       std::optional<password_manager::PasswordForm> credentials =
           GetCorrespondingPasswordForm(
               suggestion.GetPayload<Suggestion::PasswordSuggestionDetails>(),
@@ -501,7 +501,7 @@ void PasswordManualFallbackFlow::EnsureC
     const Suggestion::PasswordSuggestionDetails& payload,
     base::OnceClosure on_allowed) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (payload.is_cross_domain) {
     CHECK(payload.display_signon_realm);
     cross_domain_confirmation_popup_controller_ =
