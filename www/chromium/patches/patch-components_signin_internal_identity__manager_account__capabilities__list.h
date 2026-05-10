$NetBSD: patch-components_signin_internal_identity__manager_account__capabilities__list.h,v 1.1 2026/05/10 15:29:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/signin/internal/identity_manager/account_capabilities_list.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ components/signin/internal/identity_manager/account_capabilities_list.h
@@ -71,7 +71,7 @@ ACCOUNT_CAPABILITY(
     CAN_SHOW_HISTORY_SYNC_OPT_INS_WITHOUT_MINOR_MODE_RESTRICTIONS_CAPABILITY_NAME,
     "accountcapabilities/gi2tklldmfya")
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 ACCOUNT_CAPABILITY(kCanSubmitFeedbackInChromeCapabilityName,
                    CAN_SUBMIT_FEEDBACK_IN_CHROME_CAPABILITY_NAME,
                    "accountcapabilities/gizdqmrnmnqxa")
