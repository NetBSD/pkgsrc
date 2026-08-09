$NetBSD: patch-components_policy_core_browser_policy__pref__mapping__test.cc,v 1.24 2026/08/09 06:31:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/policy/core/browser/policy_pref_mapping_test.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ components/policy/core/browser/policy_pref_mapping_test.cc
@@ -434,7 +434,7 @@ class PolicyTestCase {
     const std::string os("chromeos");
 #elif BUILDFLAG(IS_IOS)
     const std::string os("ios");
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     const std::string os("linux");
 #elif BUILDFLAG(IS_MAC)
     const std::string os("mac");
