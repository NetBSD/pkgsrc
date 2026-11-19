$NetBSD: patch-components_supervised__user_core_common_pref__names.h,v 1.33 2026/11/19 19:46:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/supervised_user/core/common/pref_names.h.orig	2026-11-11 21:01:38.000000000 +0000
+++ components/supervised_user/core/common/pref_names.h
@@ -118,7 +118,7 @@ inline constexpr char kDefaultSupervised
     "profile.managed.default_filtering_behavior";
 
 #if BUILDFLAG(ENABLE_EXTENSIONS_CORE)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // An integer pref that stores the current state of the local extension
 // parent approval migration when the feature
 // `kEnableSupervisedUserSkipParentApprovalToInstallExtensions` becomes enabled.
