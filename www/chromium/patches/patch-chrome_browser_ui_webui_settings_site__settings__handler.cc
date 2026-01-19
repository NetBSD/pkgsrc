$NetBSD: patch-chrome_browser_ui_webui_settings_site__settings__handler.cc,v 1.6 2026/01/19 16:14:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/settings/site_settings_handler.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/ui/webui/settings/site_settings_handler.cc
@@ -124,7 +124,7 @@
 #include "url/url_constants.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/webapps/isolated_web_apps/scheme.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -2087,7 +2087,7 @@ void SiteSettingsHandler::SendZoomLevels
   base::Value::List zoom_levels_exceptions;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Show any non-default Isolated Web App zoom levels at the top of the page.
   auto* web_app_provider = web_app::WebAppProvider::GetForWebApps(profile_);
   if (web_app_provider) {
@@ -2189,7 +2189,7 @@ void SiteSettingsHandler::HandleRemoveZo
   GURL url(host_or_spec);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (url.is_valid() && url.GetScheme() == webapps::kIsolatedAppScheme) {
     base::expected<web_app::IsolatedWebAppUrlInfo, std::string> iwa_url_info =
         web_app::IsolatedWebAppUrlInfo::Create(url);
