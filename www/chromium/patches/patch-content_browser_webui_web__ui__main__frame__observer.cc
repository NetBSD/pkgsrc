$NetBSD: patch-content_browser_webui_web__ui__main__frame__observer.cc,v 1.14 2026/01/19 16:14:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/webui/web_ui_main_frame_observer.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ content/browser/webui/web_ui_main_frame_observer.cc
@@ -47,7 +47,7 @@ std::string RedactURL(const GURL& url) {
 bool IsWebUIJavaScriptErrorReportingSupported() {
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
   return false;
-#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return base::FeatureList::IsEnabled(features::kWebUIJSErrorReportingExtended);
