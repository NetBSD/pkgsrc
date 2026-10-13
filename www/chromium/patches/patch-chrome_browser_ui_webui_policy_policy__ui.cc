$NetBSD: patch-chrome_browser_ui_webui_policy_policy__ui.cc,v 1.6 2026/10/13 13:16:36 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/policy/policy_ui.cc.orig	2026-10-06 00:06:58.000000000 +0000
+++ chrome/browser/ui/webui/policy/policy_ui.cc
@@ -188,7 +188,7 @@ void CreateAndAddPolicyUIHtmlSource(Prof
       {"statusFlexOrgNoPolicy", IDS_POLICY_STATUS_FLEX_ORG_NO_POLICY},
       {"statusDevice", IDS_POLICY_STATUS_DEVICE},
       {"statusMachine", IDS_POLICY_STATUS_MACHINE},
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       {"statusUpdater", IDS_POLICY_STATUS_UPDATER},
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
       {"statusUser", IDS_POLICY_STATUS_USER},
