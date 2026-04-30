$NetBSD: patch-src_3rdparty_chromium_chrome_browser_net_profile__network__context__service__factory.cc,v 1.1 2026/04/30 06:39:36 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/browser/net/profile_network_context_service_factory.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/net/profile_network_context_service_factory.cc
@@ -32,7 +32,7 @@
 #include "chrome/browser/net/server_certificate_database_service_factory.h"  // nogncheck
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/client_certificates/certificate_provisioning_service_factory.h"
 #endif
 
@@ -76,7 +76,7 @@ ProfileNetworkContextServiceFactory::Pro
 #if BUILDFLAG(CHROME_ROOT_STORE_CERT_MANAGEMENT_UI)
   DependsOn(net::ServerCertificateDatabaseServiceFactory::GetInstance());
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   DependsOn(client_certificates::CertificateProvisioningServiceFactory::
                 GetInstance());
 #endif
