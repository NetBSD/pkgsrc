$NetBSD: patch-chrome_browser_ui_webui_connectors__internals_connectors__internals__page__handler.cc,v 1.3 2025/08/13 07:44:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/connectors_internals/connectors_internals_page_handler.cc.orig	2025-07-29 22:51:44.000000000 +0000
+++ chrome/browser/ui/webui/connectors_internals/connectors_internals_page_handler.cc
@@ -82,7 +82,7 @@ connectors_internals::mojom::ClientIdent
 }
 #endif  // BUILDFLAG(ENTERPRISE_CLIENT_CERTIFICATES)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::string GetStringFromTimestamp(base::Time timestamp) {
   return (timestamp == base::Time()) ? std::string()
                                      : base::UnlocalizedTimeFormatWithPattern(
@@ -191,7 +191,7 @@ void ConnectorsInternalsPageHandler::Get
 
 void ConnectorsInternalsPageHandler::GetSignalsReportingState(
     GetSignalsReportingStateCallback callback) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* profile_prefs = profile_->GetPrefs();
 
   std::string last_upload_attempt_time_string =
