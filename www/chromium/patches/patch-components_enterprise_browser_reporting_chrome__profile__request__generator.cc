$NetBSD: patch-components_enterprise_browser_reporting_chrome__profile__request__generator.cc,v 1.5 2026/10/13 13:16:38 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/enterprise/browser/reporting/chrome_profile_request_generator.cc.orig	2026-10-06 00:06:58.000000000 +0000
+++ components/enterprise/browser/reporting/chrome_profile_request_generator.cc
@@ -213,7 +213,7 @@ void ChromeProfileRequestGenerator::OnBa
   signals_request.signal_names.emplace(device_signals::SignalName::kHotfixes);
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (enterprise_signals::features::IsCertificateCollectionEnabled() &&
       generation_config.challenge.has_value() &&
       !generation_config.challenge.value().empty()) {
