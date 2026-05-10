$NetBSD: patch-chrome_browser_ui_webui_connectors__internals_connectors__internals__page__handler.cc,v 1.17 2026/05/10 15:29:53 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/connectors_internals/connectors_internals_page_handler.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/ui/webui/connectors_internals/connectors_internals_page_handler.cc
@@ -75,7 +75,7 @@ std::string ConvertPolicyLevelToString(D
 #endif  // !BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 std::string GetStringFromTimestamp(base::Time timestamp) {
   return (timestamp == base::Time()) ? std::string()
                                      : base::UnlocalizedTimeFormatWithPattern(
@@ -190,7 +190,7 @@ void ConnectorsInternalsPageHandler::Get
 void ConnectorsInternalsPageHandler::GetSignalsReportingState(
     GetSignalsReportingStateCallback callback) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   auto* profile_prefs = profile_->GetPrefs();
 
   std::string last_upload_attempt_time_string =
@@ -331,7 +331,7 @@ void ConnectorsInternalsPageHandler::OnS
 #endif  // !BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 void ConnectorsInternalsPageHandler::OnReportGenerated(
     GetSignalsReportingStateCallback callback,
     connectors_internals::mojom::SignalsReportingStatePtr state,
