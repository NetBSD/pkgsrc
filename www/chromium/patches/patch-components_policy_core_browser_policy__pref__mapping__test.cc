$NetBSD: patch-components_policy_core_browser_policy__pref__mapping__test.cc,v 1.32 2026/11/08 15:39:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/policy/core/browser/policy_pref_mapping_test.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ components/policy/core/browser/policy_pref_mapping_test.cc
@@ -461,7 +461,7 @@ class PolicyTestCase {
     static constexpr std::string_view kOsList[] = {"chromeos"};
 #elif BUILDFLAG(IS_IOS)
     static constexpr std::string_view kOsList[] = {"ios"};
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     static constexpr std::string_view kOsList[] = {"linux"};
 #elif BUILDFLAG(IS_MAC)
     static constexpr std::string_view kOsList[] = {"mac"};
