$NetBSD: patch-chrome_browser_enterprise_connectors_device__trust_device__trust__connector__service__factory.cc,v 1.1 2025/02/06 09:57:46 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/connectors/device_trust/device_trust_connector_service_factory.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/enterprise/connectors/device_trust/device_trust_connector_service_factory.cc
@@ -10,7 +10,7 @@
 #include "chrome/browser/profiles/profile.h"
 #include "components/keyed_service/core/keyed_service.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_process.h"
 #include "chrome/browser/enterprise/connectors/device_trust/browser/signing_key_policy_observer.h"
 #include "chrome/browser/policy/chrome_browser_policy_connector.h"
@@ -40,7 +40,7 @@ DeviceTrustConnectorService* DeviceTrust
 
 bool DeviceTrustConnectorServiceFactory::ServiceIsCreatedWithBrowserContext()
     const {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
@@ -84,7 +84,7 @@ DeviceTrustConnectorServiceFactory::Buil
   std::unique_ptr<DeviceTrustConnectorService> service =
       std::make_unique<DeviceTrustConnectorService>(profile->GetPrefs());
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   auto* key_manager = g_browser_process->browser_policy_connector()
                           ->chrome_browser_cloud_management_controller()
                           ->GetDeviceTrustKeyManager();
