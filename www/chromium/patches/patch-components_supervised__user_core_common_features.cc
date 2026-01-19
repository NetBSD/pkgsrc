$NetBSD: patch-components_supervised__user_core_common_features.cc,v 1.14 2026/01/19 16:14:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/supervised_user/core/common/features.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ components/supervised_user/core/common/features.cc
@@ -32,7 +32,7 @@ BASE_FEATURE(kAllowSubframeLocalWebAppro
 #endif
 
 #if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD) 
 const int kLocalWebApprovalBottomSheetLoadTimeoutDefaultValueMs = 5000;
 
 const base::FeatureParam<int> kLocalWebApprovalBottomSheetLoadTimeoutMs{
@@ -41,7 +41,7 @@ const base::FeatureParam<int> kLocalWebA
 #endif  // BUILDFLAG(IS_IOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD) 
 BASE_FEATURE(kEnableLocalWebApprovalErrorDialog,
              base::FEATURE_ENABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
@@ -53,7 +53,7 @@ BASE_FEATURE(kLocalWebApprovalsWidgetSup
 // TODO(crbug.com/435635774): Release the interstitial v3 in all platforms.
 BASE_FEATURE(kSupervisedUserBlockInterstitialV3,
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -89,7 +89,7 @@ bool IsLocalWebApprovalsEnabledForSubfra
   return base::FeatureList::IsEnabled(kAllowSubframeLocalWebApprovals);
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD) 
 BASE_FEATURE(kEnableSupervisedUserVersionSignOutDialog,
              base::FEATURE_ENABLED_BY_DEFAULT);
 #endif
