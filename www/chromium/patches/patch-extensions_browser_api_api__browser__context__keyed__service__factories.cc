$NetBSD: patch-extensions_browser_api_api__browser__context__keyed__service__factories.cc,v 1.14 2026/01/19 16:14:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- extensions/browser/api/api_browser_context_keyed_service_factories.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ extensions/browser/api/api_browser_context_keyed_service_factories.cc
@@ -123,7 +123,7 @@ void EnsureApiBrowserContextKeyedService
   MediaPerceptionAPIManager::GetFactoryInstance();
 #endif
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   NetworkingPrivateEventRouterFactory::GetInstance();
 #endif
   PrinterProviderAPIFactory::GetInstance();
