$NetBSD: patch-chrome_browser_ui_ui__features.cc,v 1.32 2026/11/08 15:38:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/ui_features.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ chrome/browser/ui/ui_features.cc
@@ -139,7 +139,7 @@ bool ShouldUseActionsForBrowserCommands(
          base::FeatureList::IsEnabled(kAppMenuGlowUp);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kDseIntegrity, base::FEATURE_ENABLED_BY_DEFAULT);
 
 // Enables the dialog shown when user feedback is disabled.
@@ -380,7 +380,7 @@ BASE_FEATURE(kByDateHistoryInSidePanel, 
 
 BASE_FEATURE(kNonMilestoneUpdateToast, base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kRespectShouldTriggerSessionRestoreOnDesktop,
              base::FEATURE_ENABLED_BY_DEFAULT);
 
