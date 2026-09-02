$NetBSD: patch-chrome_renderer_chrome__content__renderer__client.cc,v 1.17 2026/09/02 13:13:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/renderer/chrome_content_renderer_client.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/renderer/chrome_content_renderer_client.cc
@@ -188,7 +188,7 @@
 #include "v8/include/v8-isolate.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/webapps/isolated_web_apps/scheme.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -438,7 +438,7 @@ void ChromeContentRendererClient::Render
   WebSecurityPolicy::RegisterURLSchemeAsExtension(
       WebString::FromAscii(extensions::kExtensionScheme));
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   WebSecurityPolicy::RegisterURLSchemeAsIsolatedApp(
       WebString::FromAscii(webapps::kIsolatedAppScheme));
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
@@ -503,7 +503,7 @@ void ChromeContentRendererClient::Render
       WebString::FromAscii(chrome::kChromeSearchScheme));
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // IWAs can be enabled by either the feature flag or by enterprise
   // policy. In either case the kEnableIsolatedWebAppsInRenderer flag is passed
   // to the renderer process.
@@ -558,7 +558,7 @@ void ChromeContentRendererClient::Render
   WebSecurityPolicy::RegisterURLSchemeAsDisplayIsolated(dom_distiller_scheme);
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(features::kGoogleChromeScheme)) {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
     WebSecurityPolicy::RegisterURLSchemeAsDirectLaunch(
