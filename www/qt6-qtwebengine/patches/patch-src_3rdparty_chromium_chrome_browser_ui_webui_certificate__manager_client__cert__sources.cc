$NetBSD: patch-src_3rdparty_chromium_chrome_browser_ui_webui_certificate__manager_client__cert__sources.cc,v 1.1 2025/12/21 09:38:19 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/browser/ui/webui/certificate_manager/client_cert_sources.cc.orig	2025-11-14 07:55:10.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/ui/webui/certificate_manager/client_cert_sources.cc
@@ -54,7 +54,7 @@
 #include "net/ssl/client_cert_store_mac.h"
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/client_certificates/certificate_provisioning_service_factory.h"
 #include "components/enterprise/client_certificates/core/certificate_provisioning_service.h"
 #include "components/enterprise/client_certificates/core/client_certificates_service.h"
@@ -174,7 +174,7 @@ class ClientCertStoreFactoryMac : public
 };
 #endif
 
-#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 std::unique_ptr<ClientCertStoreLoader> CreatePlatformClientCertLoader(
     Profile* profile) {
 #if BUILDFLAG(IS_WIN)
@@ -189,7 +189,7 @@ std::unique_ptr<ClientCertStoreLoader> C
 }
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // ClientCertStore implementation that always returns an empty list. The
 // CertificateProvisioningService implementation expects to wrap a platform
 // cert store, but here we only want to get results from the provisioning
@@ -347,7 +347,7 @@ class ClientCertSource : public Certific
   std::optional<net::CertificateList> certs_;
 };
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // ChromeOS currently can use either Kcer or NSS for listing client certs, and
 // Linux uses NSS only. This interface provides an abstraction to hide that
 // from WritableClientCertSource. Currently this class only handles reading
@@ -1078,7 +1078,7 @@ CreatePlatformClientCertSource(
     mojo::Remote<certificate_manager_v2::mojom::CertificateManagerPage>*
         remote_client,
     Profile* profile) {
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return std::make_unique<WritableClientCertSource>(remote_client, profile);
 #else
   return std::make_unique<ClientCertSource>(
@@ -1086,7 +1086,7 @@ CreatePlatformClientCertSource(
 #endif
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::unique_ptr<CertificateManagerPageHandler::CertSource>
 CreateProvisionedClientCertSource(Profile* profile) {
   return std::make_unique<ClientCertSource>(
@@ -1135,7 +1135,7 @@ bool ClientCertManagementAccessControls:
 
   return client_cert_policy_ == ClientCertificateManagementPermission::kAll;
 }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 ClientCertManagementAccessControls::ClientCertManagementAccessControls(
     Profile* profile) {}
 
