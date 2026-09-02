$NetBSD: patch-components_signin_public_identity__manager_account__capabilities.h,v 1.7 2026/09/02 13:13:30 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/signin/public/identity_manager/account_capabilities.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ components/signin/public/identity_manager/account_capabilities.h
@@ -93,7 +93,7 @@ class AccountCapabilities {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   // Whether the account can submit feedback. For iOS, this is implemented by
   // Aloha FeedbackKit. For Android, this is implemented by GMS Core.
   signin::Tribool can_submit_feedback() const;
