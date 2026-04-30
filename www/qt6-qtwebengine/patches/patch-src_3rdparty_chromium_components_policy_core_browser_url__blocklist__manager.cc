$NetBSD: patch-src_3rdparty_chromium_components_policy_core_browser_url__blocklist__manager.cc,v 1.1 2026/04/30 06:39:39 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/policy/core/browser/url_blocklist_manager.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/components/policy/core/browser/url_blocklist_manager.cc
@@ -377,7 +377,7 @@ void URLBlocklistManager::RegisterProfil
       policy_prefs::kSafeSitesFilterBehavior,
       static_cast<int>(SafeSitesFilterBehavior::kSafeSitesFilterDisabled));
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   registry->RegisterListPref(policy_prefs::kPasswordManagerBlocklist);
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) ||
         // BUILDFLAG(IS_MAC)
