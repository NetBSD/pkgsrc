$NetBSD: patch-components_supervised__user_core_common_features.h,v 1.25 2026/09/02 13:13:30 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/supervised_user/core/common/features.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ components/supervised_user/core/common/features.h
@@ -20,12 +20,12 @@ BASE_DECLARE_FEATURE(kLocalWebApprovals)
 BASE_DECLARE_FEATURE(kAllowSubframeLocalWebApprovals);
 
 #if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 extern const base::FeatureParam<int> kLocalWebApprovalBottomSheetLoadTimeoutMs;
 #endif  // BUILDFLAG(IS_IOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Uses supervised user strings on the signout dialog.
 BASE_DECLARE_FEATURE(kEnableSupervisedUserVersionSignOutDialog);
 #endif
