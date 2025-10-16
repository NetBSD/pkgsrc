$NetBSD: patch-chrome_browser_supervised__user_supervised__user__extensions__manager.h,v 1.8 2025/10/16 19:43:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/supervised_user/supervised_user_extensions_manager.h.orig	2025-10-13 21:41:26.000000000 +0000
+++ chrome/browser/supervised_user/supervised_user_extensions_manager.h
@@ -151,7 +151,7 @@ class SupervisedUserExtensionsManager : 
   // launched.
   bool ShouldBlockExtension(const std::string& extension_id) const;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Triggers an one-time migration of the present extensions as parent-approved
   // when the feature
   // `kEnableSupervisedUserSkipParentApprovalToInstallExtensions` becomes
