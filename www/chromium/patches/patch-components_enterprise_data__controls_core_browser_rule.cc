$NetBSD: patch-components_enterprise_data__controls_core_browser_rule.cc,v 1.21 2026/09/02 13:13:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/enterprise/data_controls/core/browser/rule.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ components/enterprise/data_controls/core/browser/rule.cc
@@ -611,7 +611,7 @@ bool Rule::AddUnsupportedAttributeErrors
               },
           },
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           {
               Restriction::kFileDownload,
               {
@@ -731,7 +731,7 @@ bool Rule::AddUnsupportedRestrictionErro
           },
 #endif  // BUILDFLAG(ENTERPRISE_SCREENSHOT_PROTECTION)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           {
               Restriction::kFileDownload,
               {
