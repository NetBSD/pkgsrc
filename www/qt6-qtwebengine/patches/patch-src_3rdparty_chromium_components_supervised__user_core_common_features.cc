$NetBSD: patch-src_3rdparty_chromium_components_supervised__user_core_common_features.cc,v 1.1 2025/12/21 09:38:25 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/supervised_user/core/common/features.cc.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/components/supervised_user/core/common/features.cc
@@ -68,7 +68,7 @@ BASE_FEATURE(kUpdatedSupervisedUserExten
              "UpdatedSupervisedUserExtensionApprovalStrings",
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableExtensionsPermissionsForSupervisedUsersOnDesktop,
              "EnableExtensionsPermissionsForSupervisedUsersOnDesktop",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -83,7 +83,7 @@ bool IsSupervisedUserSkipParentApprovalT
 #if BUILDFLAG(IS_CHROMEOS)
   return base::FeatureList::IsEnabled(
       kEnableSupervisedUserSkipParentApprovalToInstallExtensions);
-#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   bool skipParentApprovalEnabled = base::FeatureList::IsEnabled(
       kEnableSupervisedUserSkipParentApprovalToInstallExtensions);
   bool permissionExtensionsForSupervisedUsersEnabled =
@@ -104,14 +104,14 @@ BASE_FEATURE(kCustomProfileStringsForSup
              "CustomProfileStringsForSupervisedUsers",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 
 BASE_FEATURE(kShowKiteForSupervisedUsers,
              "ShowKiteForSupervisedUsers",
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kForceSafeSearchForUnauthenticatedSupervisedUsers,
              "ForceSafeSearchForUnauthenticatedSupervisedUsers",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -121,7 +121,7 @@ BASE_FEATURE(kForceSafeSearchForUnauthen
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableSupervisedUserVersionSignOutDialog,
              "EnableSupervisedUserVersionSignOutDialog",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -141,7 +141,7 @@ BASE_FEATURE(kExemptYouTubeInfrastructur
 // kUncredentialedFilteringFallbackForSupervisedUsers and
 // kWaitUntilAccessTokenAvailableForClassifyUrl flags, by inlining the
 // platform #defines.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kUncredentialedFilteringFallbackForSupervisedUsers,
              "UncredentialedFilteringFallbackForSupervisedUsers",
              base::FEATURE_ENABLED_BY_DEFAULT);
