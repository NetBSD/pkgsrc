$NetBSD: patch-chrome_browser_policy_policy__value__and__status__aggregator.cc,v 1.14 2026/01/19 16:14:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/policy/policy_value_and_status_aggregator.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/policy/policy_value_and_status_aggregator.cc
@@ -49,7 +49,7 @@
 #include "chrome/browser/policy/value_provider/extension_policies_value_provider.h"
 #endif  // BUILDFLAG(ENABLE_EXTENSIONS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/policy/core/common/cloud/profile_cloud_policy_manager.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
