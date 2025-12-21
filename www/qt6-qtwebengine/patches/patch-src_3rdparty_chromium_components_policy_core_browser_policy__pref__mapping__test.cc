$NetBSD: patch-src_3rdparty_chromium_components_policy_core_browser_policy__pref__mapping__test.cc,v 1.1 2025/12/21 09:38:24 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/policy/core/browser/policy_pref_mapping_test.cc.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/components/policy/core/browser/policy_pref_mapping_test.cc
@@ -408,7 +408,7 @@ class PolicyTestCase {
     const std::string os("chromeos_ash");
 #elif BUILDFLAG(IS_IOS)
     const std::string os("ios");
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     const std::string os("linux");
 #elif BUILDFLAG(IS_MAC)
     const std::string os("mac");
