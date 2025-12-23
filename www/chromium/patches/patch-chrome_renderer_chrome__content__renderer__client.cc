$NetBSD: patch-chrome_renderer_chrome__content__renderer__client.cc,v 1.5 2025/12/23 13:22:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/renderer/chrome_content_renderer_client.cc.orig	2025-12-17 23:05:18.000000000 +0000
+++ chrome/renderer/chrome_content_renderer_client.cc
@@ -188,7 +188,7 @@
 #include "v8/include/v8-isolate.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/webapps/isolated_web_apps/scheme.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -424,7 +424,7 @@ void ChromeContentRendererClient::Render
   WebSecurityPolicy::RegisterURLSchemeAsExtension(
       WebString::FromASCII(extensions::kExtensionScheme));
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   WebSecurityPolicy::RegisterURLSchemeAsIsolatedApp(
       WebString::FromASCII(webapps::kIsolatedAppScheme));
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
@@ -500,7 +500,7 @@ void ChromeContentRendererClient::Render
       WebString::FromASCII(chrome::kChromeSearchScheme));
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // IWAs can be enabled by either the feature flag or by enterprise
   // policy. In either case the kEnableIsolatedWebAppsInRenderer flag is passed
   // to the renderer process.
