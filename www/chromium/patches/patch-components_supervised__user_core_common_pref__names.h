$NetBSD: patch-components_supervised__user_core_common_pref__names.h,v 1.6 2025/09/08 13:24:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/supervised_user/core/common/pref_names.h.orig	2025-08-29 18:50:09.000000000 +0000
+++ components/supervised_user/core/common/pref_names.h
@@ -129,7 +129,7 @@ inline constexpr char kDefaultSupervised
     "profile.managed.default_filtering_behavior";
 
 #if BUILDFLAG(ENABLE_EXTENSIONS_CORE)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // An integer pref that stores the current state of the local extension
 // parent approval migration when the feature
 // `kEnableSupervisedUserSkipParentApprovalToInstallExtensions` becomes enabled.
