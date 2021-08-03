$NetBSD: patch-src_3rdparty_chromium_extensions_browser_browser__context__keyed__service__factories.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/extensions/browser/browser_context_keyed_service_factories.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/extensions/browser/browser_context_keyed_service_factories.cc
@@ -81,7 +81,7 @@ void EnsureBrowserContextKeyedServiceFac
   IdleManagerFactory::GetInstance();
 #endif // !defined(TOOLKIT_QT)
   ManagementAPI::GetFactoryInstance();
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD)
   NetworkingPrivateEventRouterFactory::GetInstance();
 #endif
   PowerAPI::GetFactoryInstance();
