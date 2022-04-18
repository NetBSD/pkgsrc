$NetBSD: patch-src_3rdparty_chromium_extensions_browser_browser__context__keyed__service__factories.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/extensions/browser/browser_context_keyed_service_factories.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/extensions/browser/browser_context_keyed_service_factories.cc
@@ -107,7 +107,7 @@ void EnsureBrowserContextKeyedServiceFac
   NetworkingConfigServiceFactory::GetInstance();
 #endif
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || \
-    defined(OS_MAC)
+    defined(OS_MAC) || defined(OS_BSD)
   NetworkingPrivateEventRouterFactory::GetInstance();
 #endif
   PowerAPI::GetFactoryInstance();
