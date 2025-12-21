$NetBSD: patch-src_3rdparty_chromium_components_supervised__user_core_common_pref__names.h,v 1.1 2025/12/21 09:38:25 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/supervised_user/core/common/pref_names.h.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/components/supervised_user/core/common/pref_names.h
@@ -129,7 +129,7 @@ inline constexpr char kDefaultSupervised
     "profile.managed.default_filtering_behavior";
 
 #if BUILDFLAG(ENABLE_EXTENSIONS)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // An integer pref that stores the current state of the local extension
 // parent approval migration when the feature
 // `kEnableSupervisedUserSkipParentApprovalToInstallExtensions` becomes enabled.
