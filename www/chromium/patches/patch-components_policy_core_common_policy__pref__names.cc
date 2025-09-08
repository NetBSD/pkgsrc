$NetBSD: patch-components_policy_core_common_policy__pref__names.cc,v 1.4 2025/09/08 13:24:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/policy/core/common/policy_pref_names.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ components/policy/core/common/policy_pref_names.cc
@@ -199,7 +199,7 @@ const char kFloatingWorkspaceEnabled[] =
 // A boolean value indicating whether the built-in AI APIs are enabled.
 const char kBuiltInAIAPIsEnabled[] = "policy.built_in_ai_apis_enabled";
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 // List of urls for which password manager is disabled/blocked.
 const char kPasswordManagerBlocklist[] = "policy.password_manager_blocklist";
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) ||
