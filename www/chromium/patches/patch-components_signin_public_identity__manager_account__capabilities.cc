$NetBSD: patch-components_signin_public_identity__manager_account__capabilities.cc,v 1.14 2026/11/08 15:39:01 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/signin/public/identity_manager/account_capabilities.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ components/signin/public/identity_manager/account_capabilities.cc
@@ -152,7 +152,7 @@ signin::Tribool AccountCapabilities::can
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
 signin::Tribool AccountCapabilities::can_submit_feedback() const {
   return GetCapabilityByName(kCanSubmitFeedbackInChromeCapabilityName);
 }
