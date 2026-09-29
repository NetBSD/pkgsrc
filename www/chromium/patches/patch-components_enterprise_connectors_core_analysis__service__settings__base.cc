$NetBSD: patch-components_enterprise_connectors_core_analysis__service__settings__base.cc,v 1.1 2026/09/29 07:42:54 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/enterprise/connectors/core/analysis_service_settings_base.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ components/enterprise/connectors/core/analysis_service_settings_base.cc
@@ -283,7 +283,7 @@ void AnalysisServiceSettingsBase::ParseV
   const char* verification_key = kKeyWindowsVerification;
 #elif BUILDFLAG(IS_MAC)
   const char* verification_key = kKeyMacVerification;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const char* verification_key = kKeyLinuxVerification;
 #endif
 
