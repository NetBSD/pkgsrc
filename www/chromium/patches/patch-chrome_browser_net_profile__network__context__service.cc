$NetBSD: patch-chrome_browser_net_profile__network__context__service.cc,v 1.3 2025/07/07 09:23:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/net/profile_network_context_service.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ chrome/browser/net/profile_network_context_service.cc
@@ -135,7 +135,7 @@
 #include "extensions/common/constants.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/client_certificates/certificate_provisioning_service_factory.h"
 #include "chrome/browser/policy/chrome_browser_policy_connector.h"
 #include "components/enterprise/browser/controller/chrome_browser_cloud_management_controller.h"
@@ -276,7 +276,7 @@ void UpdateCookieSettings(Profile* profi
       });
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::unique_ptr<net::ClientCertStore> GetWrappedCertStore(
     Profile* profile,
     std::unique_ptr<net::ClientCertStore> platform_store) {
@@ -1224,7 +1224,7 @@ ProfileNetworkContextService::CreateClie
       std::make_unique<net::ClientCertStoreNSS>(
           base::BindRepeating(&CreateCryptoModuleBlockingPasswordDelegate,
                               kCryptoModulePasswordClientAuth));
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return GetWrappedCertStore(profile_, std::move(store));
 #else
   return store;
