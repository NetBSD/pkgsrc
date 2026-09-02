$NetBSD: patch-components_signin_public_identity__manager_account__capabilities.cc,v 1.7 2026/09/02 13:13:30 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/signin/public/identity_manager/account_capabilities.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ components/signin/public/identity_manager/account_capabilities.cc
@@ -192,7 +192,7 @@ signin::Tribool AccountCapabilities::can
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
 signin::Tribool AccountCapabilities::can_submit_feedback() const {
   return GetCapabilityByName(kCanSubmitFeedbackInChromeCapabilityName);
 }
