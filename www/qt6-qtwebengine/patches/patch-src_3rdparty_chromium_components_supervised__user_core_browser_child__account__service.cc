$NetBSD: patch-src_3rdparty_chromium_components_supervised__user_core_browser_child__account__service.cc,v 1.1 2026/04/30 06:39:39 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/supervised_user/core/browser/child_account_service.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/components/supervised_user/core/browser/child_account_service.cc
@@ -170,7 +170,7 @@ void ChildAccountService::OnPrimaryAccou
 void ChildAccountService::UpdateForceGoogleSafeSearch() {
 // On platforms without web sign-out (where the primary account is always
 // authenticated), there's no need to force SafeSearch.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   bool is_subject_to_parental_controls =
       IsPrimaryAccountSubjectToParentalControls(identity_manager_) ==
       signin::Tribool::kTrue;
