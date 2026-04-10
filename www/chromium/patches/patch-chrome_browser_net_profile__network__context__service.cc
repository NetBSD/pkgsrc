$NetBSD: patch-chrome_browser_net_profile__network__context__service.cc,v 1.17 2026/04/10 17:31:49 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/net/profile_network_context_service.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ chrome/browser/net/profile_network_context_service.cc
@@ -145,7 +145,7 @@
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/client_certificates/certificate_provisioning_service_factory.h"
 #include "chrome/browser/policy/chrome_browser_policy_connector.h"
 #include "components/enterprise/browser/controller/chrome_browser_cloud_management_controller.h"
@@ -321,7 +321,7 @@ void UpdateCookieSettings(Profile* profi
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 std::unique_ptr<net::ClientCertStore> GetWrappedCertStore(
     Profile* profile,
     std::unique_ptr<net::ClientCertStore> platform_store) {
@@ -1267,7 +1267,7 @@ ProfileNetworkContextService::CreateClie
       std::make_unique<net::ClientCertStoreNSS>(
           base::BindRepeating(&CreateCryptoModuleBlockingPasswordDelegate,
                               kCryptoModulePasswordClientAuth));
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return GetWrappedCertStore(profile_, std::move(store));
 #else
   return store;
@@ -1306,7 +1306,7 @@ std::vector<uint8_t>
 ProfileNetworkContextService::GetEncryptedCachePrimaryKey() {
   std::string encoded_encrypted_primary_key = profile_->GetPrefs()->GetString(
       enterprise_connectors::kEncryptedCachePrimaryKey);
-  return base::Base64Decode(encoded_encrypted_primary_key).value_or({});
+  return base::Base64Decode(encoded_encrypted_primary_key).value_or(std::vector<uint8_t>{});
 }
 
 #endif  // BUILDFLAG(ENTERPRISE_CACHE_ENCRYPTION)
