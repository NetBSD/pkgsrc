$NetBSD: patch-components_password__manager_core_browser_password__form__manager.cc,v 1.27 2026/09/29 07:42:54 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/password_form_manager.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ components/password_manager/core/browser/password_form_manager.cc
@@ -240,7 +240,7 @@ bool ShouldUploadCrowdsourcingVotes(cons
   return false;
 }
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool ShouldShowKeychainErrorBubble(
     std::optional<PasswordStoreBackendError> backend_error) {
   if (!backend_error.has_value()) {
@@ -949,7 +949,7 @@ void PasswordFormManager::OnFetchComplet
         error.value().type);
   }
 
-#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (ShouldShowKeychainErrorBubble(
           form_fetcher_->GetProfileStoreBackendError())) {
     client_->NotifyKeychainError();
