$NetBSD: patch-components_signin_public_identity__manager_account__capabilities.h,v 1.3 2026/06/08 13:12:39 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/signin/public/identity_manager/account_capabilities.h.orig	2026-05-28 23:24:11.000000000 +0000
+++ components/signin/public/identity_manager/account_capabilities.h
@@ -88,7 +88,7 @@ class AccountCapabilities {
   signin::Tribool can_sign_in_to_chrome() const;
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Whether the account can submit feedback. For iOS, this is implemented by
   // Aloha FeedbackKit. For Android, this is implemented by GMS Core.
   signin::Tribool can_submit_feedback() const;
