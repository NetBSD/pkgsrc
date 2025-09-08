$NetBSD: patch-components_policy_core_browser_url__blocklist__manager.cc,v 1.4 2025/09/08 13:24:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/policy/core/browser/url_blocklist_manager.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ components/policy/core/browser/url_blocklist_manager.cc
@@ -377,7 +377,7 @@ void URLBlocklistManager::RegisterProfil
       policy_prefs::kSafeSitesFilterBehavior,
       static_cast<int>(SafeSitesFilterBehavior::kSafeSitesFilterDisabled));
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   registry->RegisterListPref(policy_prefs::kPasswordManagerBlocklist);
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) ||
         // BUILDFLAG(IS_MAC)
