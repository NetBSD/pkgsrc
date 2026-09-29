$NetBSD: patch-components_signin_public_identity__manager_account__capabilities.h,v 1.9 2026/09/29 07:42:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/signin/public/identity_manager/account_capabilities.h.orig	2026-09-22 00:09:16.000000000 +0000
+++ components/signin/public/identity_manager/account_capabilities.h
@@ -100,7 +100,7 @@ class AccountCapabilities {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   // Whether the account can submit feedback. For iOS, this is implemented by
   // Aloha FeedbackKit. For Android, this is implemented by GMS Core.
   signin::Tribool can_submit_feedback() const;
