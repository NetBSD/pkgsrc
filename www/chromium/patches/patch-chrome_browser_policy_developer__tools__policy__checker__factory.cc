$NetBSD: patch-chrome_browser_policy_developer__tools__policy__checker__factory.cc,v 1.5 2026/02/15 09:03:59 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/policy/developer_tools_policy_checker_factory.cc.orig	2026-02-03 22:07:10.000000000 +0000
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
