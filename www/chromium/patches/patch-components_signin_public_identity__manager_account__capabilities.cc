$NetBSD: patch-components_signin_public_identity__manager_account__capabilities.cc,v 1.12 2026/10/16 15:30:52 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/signin/public/identity_manager/account_capabilities.cc.orig	2026-10-14 21:09:54.000000000 +0000
+++ components/signin/public/identity_manager/account_capabilities.cc
@@ -159,7 +159,7 @@ signin::Tribool AccountCapabilities::can
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
 signin::Tribool AccountCapabilities::can_submit_feedback() const {
   return GetCapabilityByName(kCanSubmitFeedbackInChromeCapabilityName);
 }
