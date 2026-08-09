$NetBSD: patch-chrome_browser_extensions_api_api__browser__context__keyed__service__factories.cc,v 1.8 2026/08/09 06:31:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/api/api_browser_context_keyed_service_factories.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/extensions/api/api_browser_context_keyed_service_factories.cc
@@ -56,7 +56,7 @@
 
 #endif  // BUILDFLAG(ENABLE_EXTENSIONS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/extensions/api/web_authentication_proxy/web_authentication_proxy_api.h"
 #include "chrome/browser/extensions/api/web_authentication_proxy/web_authentication_proxy_service.h"
 #endif
@@ -152,7 +152,7 @@ void EnsureApiBrowserContextKeyedService
 #endif  // BUILDFLAG(ENABLE_EXTENSIONS)
 
   // These APIs are intentionally not supported on desktop Android.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   extensions::WebAuthenticationProxyAPI::GetFactoryInstance();
   extensions::WebAuthenticationProxyRegistrarFactory::GetInstance();
   extensions::WebAuthenticationProxyServiceFactory::GetInstance();
