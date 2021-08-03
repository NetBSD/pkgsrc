$NetBSD: patch-src_3rdparty_chromium_headless_lib_browser_headless__request__context__manager.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/headless/lib/browser/headless_request_context_manager.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/headless/lib/browser/headless_request_context_manager.cc
@@ -27,7 +27,7 @@ namespace headless {
 
 namespace {
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 static char kProductName[] = "HeadlessChrome";
 #endif
 
@@ -57,7 +57,7 @@ net::NetworkTrafficAnnotationTag GetProx
   return traffic_annotation;
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 ::network::mojom::CryptConfigPtr BuildCryptConfigOnce(
     const base::FilePath& user_data_path) {
   static bool done_once = false;
@@ -205,7 +205,7 @@ HeadlessRequestContextManager::HeadlessR
     proxy_config_monitor_ = std::make_unique<HeadlessProxyConfigMonitor>(
         base::ThreadTaskRunnerHandle::Get());
   }
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   auto crypt_config = BuildCryptConfigOnce(user_data_path_);
   if (crypt_config)
     content::GetNetworkService()->SetCryptConfig(std::move(crypt_config));
