$NetBSD: patch-src_3rdparty_chromium_weblayer_browser_system__network__context__manager.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/weblayer/browser/system_network_context_manager.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/weblayer/browser/system_network_context_manager.cc
@@ -64,7 +64,7 @@ void SystemNetworkContextManager::Config
     network::mojom::NetworkContextParams* network_context_params,
     const std::string& user_agent) {
   network_context_params->user_agent = user_agent;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_BSD)
   // We're not configuring the cookie encryption on these platforms yet.
   network_context_params->enable_encrypted_cookies = false;
 #endif // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN)
