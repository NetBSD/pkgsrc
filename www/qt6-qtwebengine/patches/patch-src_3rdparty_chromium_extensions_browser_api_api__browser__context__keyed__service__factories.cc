$NetBSD: patch-src_3rdparty_chromium_extensions_browser_api_api__browser__context__keyed__service__factories.cc,v 1.1 2025/12/21 09:38:29 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/extensions/browser/api/api_browser_context_keyed_service_factories.cc.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/extensions/browser/api/api_browser_context_keyed_service_factories.cc
@@ -132,7 +132,7 @@ void EnsureApiBrowserContextKeyedService
 #endif
   MessageService::GetFactoryInstance();
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   NetworkingPrivateEventRouterFactory::GetInstance();
 #endif
   PrinterProviderAPIFactory::GetInstance();
