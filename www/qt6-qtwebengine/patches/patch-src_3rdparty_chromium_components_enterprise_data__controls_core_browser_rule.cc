$NetBSD: patch-src_3rdparty_chromium_components_enterprise_data__controls_core_browser_rule.cc,v 1.1 2026/04/30 06:39:38 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/enterprise/data_controls/core/browser/rule.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/components/enterprise/data_controls/core/browser/rule.cc
@@ -105,7 +105,7 @@ policy::PolicyErrorPath CreateErrorPath(
 // a type of restriction should be applied or not, check it here.
 bool IgnoreRestriction(Rule::Restriction restriction) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (restriction == Rule::Restriction::kFileDownload) {
     return !base::FeatureList::IsEnabled(kEnableDownloadDataControlsDesktop);
   }
@@ -538,7 +538,7 @@ bool Rule::AddUnsupportedAttributeErrors
               },
           },
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           {
               Restriction::kFileDownload,
               {
@@ -617,7 +617,7 @@ bool Rule::AddUnsupportedRestrictionErro
           },
 #endif  // BUILDFLAG(ENTERPRISE_SCREENSHOT_PROTECTION)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           {
               Restriction::kFileDownload,
               {
