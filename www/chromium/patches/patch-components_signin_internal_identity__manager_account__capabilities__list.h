$NetBSD: patch-components_signin_internal_identity__manager_account__capabilities__list.h,v 1.6 2026/08/09 06:31:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/signin/internal/identity_manager/account_capabilities_list.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ components/signin/internal/identity_manager/account_capabilities_list.h
@@ -72,7 +72,7 @@ ACCOUNT_CAPABILITY(
     "accountcapabilities/gi2tklldmfya")
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
 ACCOUNT_CAPABILITY(kCanSubmitFeedbackInChromeCapabilityName,
                    CAN_SUBMIT_FEEDBACK_IN_CHROME_CAPABILITY_NAME,
                    "accountcapabilities/gizdqmrnmnqxa")
