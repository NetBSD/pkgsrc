$NetBSD: patch-chrome_browser_device__identity_device__oauth2__token__service__factory.cc,v 1.30 2026/10/16 15:30:44 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/device_identity/device_oauth2_token_service_factory.cc.orig	2026-10-14 21:09:54.000000000 +0000
+++ chrome/browser/device_identity/device_oauth2_token_service_factory.cc
@@ -27,7 +27,7 @@ std::unique_ptr<DeviceOAuth2TokenStore> 
 #if BUILDFLAG(IS_CHROMEOS)
   return std::make_unique<chromeos::DeviceOAuth2TokenStoreChromeOS>(
       local_state);
-#elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return std::make_unique<DeviceOAuth2TokenStoreDesktop>(local_state,
                                                          os_crypt_async);
 #else
