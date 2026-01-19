$NetBSD: patch-chrome_browser_policy_developer__tools__policy__checker__factory.cc,v 1.4 2026/01/19 16:14:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/policy/developer_tools_policy_checker_factory.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/policy/developer_tools_policy_checker_factory.cc
@@ -58,7 +58,7 @@ void DeveloperToolsPolicyCheckerFactory:
       static_cast<int>(DeveloperToolsPolicyHandler::Availability::
                            kDisallowedForForceInstalledExtensions));
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   registry->RegisterListPref(prefs::kDeveloperToolsAvailabilityAllowlist);
   registry->RegisterListPref(prefs::kDeveloperToolsAvailabilityBlocklist);
 #endif
