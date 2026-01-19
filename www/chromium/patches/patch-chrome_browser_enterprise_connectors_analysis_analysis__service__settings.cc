$NetBSD: patch-chrome_browser_enterprise_connectors_analysis_analysis__service__settings.cc,v 1.14 2026/01/19 16:14:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/connectors/analysis/analysis_service_settings.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/enterprise/connectors/analysis/analysis_service_settings.cc
@@ -55,7 +55,7 @@ void AnalysisServiceSettings::ParseVerif
   const char* verification_key = kKeyWindowsVerification;
 #elif BUILDFLAG(IS_MAC)
   const char* verification_key = kKeyMacVerification;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const char* verification_key = kKeyLinuxVerification;
 #endif
 
