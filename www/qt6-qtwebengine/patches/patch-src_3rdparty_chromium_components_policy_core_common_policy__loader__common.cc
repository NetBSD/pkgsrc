$NetBSD: patch-src_3rdparty_chromium_components_policy_core_common_policy__loader__common.cc,v 1.2 2026/04/30 06:39:39 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/policy/core/common/policy_loader_common.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/components/policy/core/common/policy_loader_common.cc
@@ -46,7 +46,7 @@ const char* kSensitivePolicies[] = {
     key::kDefaultSearchProviderEnabled,
     key::kSafeBrowsingEnabled,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     key::kAutoOpenFileTypes,
     key::kEnterpriseSearchAggregatorSettings,
     key::kHomepageIsNewTabPage,
@@ -57,7 +57,7 @@ const char* kSensitivePolicies[] = {
     key::kSafeBrowsingAllowlistDomains,
     key::kSiteSearchSettings,
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     key::kCommandLineFlagSecurityWarningsEnabled,
     key::kEnterpriseCustomLabelForBrowser,
     key::kEnterpriseLogoUrlForBrowser,
