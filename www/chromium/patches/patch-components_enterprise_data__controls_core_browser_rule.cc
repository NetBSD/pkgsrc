$NetBSD: patch-components_enterprise_data__controls_core_browser_rule.cc,v 1.7 2025/12/11 09:13:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/enterprise/data_controls/core/browser/rule.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ components/enterprise/data_controls/core/browser/rule.cc
@@ -531,7 +531,7 @@ bool Rule::AddUnsupportedAttributeErrors
               },
           },
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           {
               Restriction::kFileDownload,
               {
@@ -610,7 +610,7 @@ bool Rule::AddUnsupportedRestrictionErro
           },
 #endif  // BUILDFLAG(ENTERPRISE_SCREENSHOT_PROTECTION)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           {
               Restriction::kFileDownload,
               {
