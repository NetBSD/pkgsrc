$NetBSD: patch-components_enterprise_browser_reporting_chrome__profile__request__generator.cc,v 1.1 2026/09/02 13:13:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/enterprise/browser/reporting/chrome_profile_request_generator.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ components/enterprise/browser/reporting/chrome_profile_request_generator.cc
@@ -210,7 +210,7 @@ void ChromeProfileRequestGenerator::OnBa
   signals_request.signal_names.emplace(device_signals::SignalName::kHotfixes);
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (enterprise_signals::features::IsCertificateCollectionEnabled() &&
       generation_config.challenge.has_value() &&
       !generation_config.challenge.value().empty()) {
