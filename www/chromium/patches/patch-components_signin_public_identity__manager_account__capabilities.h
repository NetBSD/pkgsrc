$NetBSD: patch-components_signin_public_identity__manager_account__capabilities.h,v 1.1 2026/05/10 15:29:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/signin/public/identity_manager/account_capabilities.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ components/signin/public/identity_manager/account_capabilities.h
@@ -88,7 +88,7 @@ class AccountCapabilities {
   signin::Tribool can_sign_in_to_chrome() const;
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Whether the account can submit feedback. For iOS, this is implemented by
   // Aloha FeedbackKit. For Android, this is implemented by GMS Core.
   signin::Tribool can_submit_feedback() const;
