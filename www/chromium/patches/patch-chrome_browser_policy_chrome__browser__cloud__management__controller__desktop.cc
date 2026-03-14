$NetBSD: patch-chrome_browser_policy_chrome__browser__cloud__management__controller__desktop.cc,v 1.16 2026/03/14 12:40:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/policy/chrome_browser_cloud_management_controller_desktop.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ chrome/browser/policy/chrome_browser_cloud_management_controller_desktop.cc
@@ -59,7 +59,7 @@
 #include "chrome/browser/policy/browser_dm_token_storage_mac.h"
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/policy/browser_dm_token_storage_linux.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -68,7 +68,7 @@
 #include "chrome/install_static/install_util.h"
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/client_certificates/browser_context_delegate.h"
 #include "chrome/browser/enterprise/client_certificates/cert_utils.h"
 #include "chrome/browser/enterprise/connectors/device_trust/key_management/browser/device_trust_key_manager_impl.h"
@@ -113,7 +113,7 @@ void ChromeBrowserCloudManagementControl
 
 #if BUILDFLAG(IS_MAC)
   storage_delegate = std::make_unique<BrowserDMTokenStorageMac>();
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   storage_delegate = std::make_unique<BrowserDMTokenStorageLinux>();
 #elif BUILDFLAG(IS_WIN)
   storage_delegate = std::make_unique<BrowserDMTokenStorageWin>();
@@ -285,7 +285,7 @@ ChromeBrowserCloudManagementControllerDe
 
 std::unique_ptr<enterprise_connectors::DeviceTrustKeyManager>
 ChromeBrowserCloudManagementControllerDesktop::CreateDeviceTrustKeyManager() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   auto* browser_dm_token_storage = BrowserDMTokenStorage::Get();
   auto* device_management_service = GetDeviceManagementService();
   auto shared_url_loader_factory = GetSharedURLLoaderFactory();
@@ -307,7 +307,7 @@ ChromeBrowserCloudManagementControllerDe
 std::unique_ptr<client_certificates::CertificateProvisioningService>
 ChromeBrowserCloudManagementControllerDesktop::
     CreateCertificateProvisioningService() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (!certificate_store_) {
     certificate_store_ =
         std::make_unique<client_certificates::PrefsCertificateStore>(
