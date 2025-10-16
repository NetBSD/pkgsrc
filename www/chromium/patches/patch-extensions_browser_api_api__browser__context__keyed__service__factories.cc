$NetBSD: patch-extensions_browser_api_api__browser__context__keyed__service__factories.cc,v 1.8 2025/10/16 19:43:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- extensions/browser/api/api_browser_context_keyed_service_factories.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ extensions/browser/api/api_browser_context_keyed_service_factories.cc
@@ -121,7 +121,7 @@ void EnsureApiBrowserContextKeyedService
   MediaPerceptionAPIManager::GetFactoryInstance();
 #endif
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   NetworkingPrivateEventRouterFactory::GetInstance();
 #endif
   PrinterProviderAPIFactory::GetInstance();
