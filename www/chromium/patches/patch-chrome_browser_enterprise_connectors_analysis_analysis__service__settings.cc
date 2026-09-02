$NetBSD: patch-chrome_browser_enterprise_connectors_analysis_analysis__service__settings.cc,v 1.25 2026/09/02 13:13:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/connectors/analysis/analysis_service_settings.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/enterprise/connectors/analysis/analysis_service_settings.cc
@@ -54,7 +54,7 @@ void AnalysisServiceSettings::ParseVerif
   const char* verification_key = kKeyWindowsVerification;
 #elif BUILDFLAG(IS_MAC)
   const char* verification_key = kKeyMacVerification;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const char* verification_key = kKeyLinuxVerification;
 #endif
 
