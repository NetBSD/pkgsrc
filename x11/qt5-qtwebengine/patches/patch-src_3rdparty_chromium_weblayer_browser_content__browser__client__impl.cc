$NetBSD: patch-src_3rdparty_chromium_weblayer_browser_content__browser__client__impl.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/weblayer/browser/content_browser_client_impl.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/weblayer/browser/content_browser_client_impl.cc
@@ -135,7 +135,7 @@
 #include "weblayer/browser/weblayer_factory_impl_android.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 #include "content/public/common/content_descriptors.h"
 #endif
 
@@ -382,7 +382,7 @@ void ContentBrowserClientImpl::Configure
 
 void ContentBrowserClientImpl::OnNetworkServiceCreated(
     network::mojom::NetworkService* network_service) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   network::mojom::CryptConfigPtr config = network::mojom::CryptConfig::New();
   content::GetNetworkService()->SetCryptConfig(std::move(config));
 #endif
@@ -825,7 +825,7 @@ SafeBrowsingService* ContentBrowserClien
 }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 void ContentBrowserClientImpl::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
