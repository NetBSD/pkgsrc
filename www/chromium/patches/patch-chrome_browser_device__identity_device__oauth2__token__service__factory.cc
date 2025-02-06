$NetBSD: patch-chrome_browser_device__identity_device__oauth2__token__service__factory.cc,v 1.1 2025/02/06 09:57:46 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/device_identity/device_oauth2_token_service_factory.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/device_identity/device_oauth2_token_service_factory.cc
@@ -28,7 +28,7 @@ std::unique_ptr<DeviceOAuth2TokenStore> 
   return std::make_unique<chromeos::DeviceOAuth2TokenStoreChromeOS>(
       local_state);
 #elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_BSD)
   return std::make_unique<DeviceOAuth2TokenStoreDesktop>(local_state);
 #else
   NOTREACHED_IN_MIGRATION();
