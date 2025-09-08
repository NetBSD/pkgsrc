$NetBSD: patch-components_policy_core_common_policy__pref__names.h,v 1.4 2025/09/08 13:24:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/policy/core/common/policy_pref_names.h.orig	2025-08-29 18:50:09.000000000 +0000
+++ components/policy/core/common/policy_pref_names.h
@@ -94,7 +94,7 @@ extern const char kFloatingWorkspaceEnab
 #endif
 extern const char kBuiltInAIAPIsEnabled[];
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 extern const char kPasswordManagerBlocklist[];
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
