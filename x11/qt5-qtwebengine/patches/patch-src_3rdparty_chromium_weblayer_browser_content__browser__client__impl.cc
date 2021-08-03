$NetBSD: patch-src_3rdparty_chromium_weblayer_browser_content__browser__client__impl.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/weblayer/browser/content_browser_client_impl.cc.orig	2020-07-15 18:56:49.000000000 +0000
+++ src/3rdparty/chromium/weblayer/browser/content_browser_client_impl.cc
@@ -120,7 +120,7 @@
 #include "weblayer/browser/safe_browsing/safe_browsing_service.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 #include "content/public/common/content_descriptors.h"
 #endif
 
@@ -355,7 +355,7 @@ void ContentBrowserClientImpl::Configure
 
 void ContentBrowserClientImpl::OnNetworkServiceCreated(
     network::mojom::NetworkService* network_service) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   network::mojom::CryptConfigPtr config = network::mojom::CryptConfig::New();
   content::GetNetworkService()->SetCryptConfig(std::move(config));
 #endif
@@ -708,7 +708,7 @@ SafeBrowsingService* ContentBrowserClien
 }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 void ContentBrowserClientImpl::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
