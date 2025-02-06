$NetBSD: patch-extensions_browser_api_networking__private_networking__private__delegate__factory.cc,v 1.1 2025/02/06 09:58:09 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- extensions/browser/api/networking_private/networking_private_delegate_factory.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ extensions/browser/api/networking_private/networking_private_delegate_factory.cc
@@ -12,7 +12,7 @@
 
 #if BUILDFLAG(IS_CHROMEOS)
 #include "extensions/browser/api/networking_private/networking_private_chromeos.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "extensions/browser/api/networking_private/networking_private_linux.h"
 #elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 #include "components/wifi/wifi_service.h"
@@ -63,7 +63,7 @@ NetworkingPrivateDelegateFactory::BuildS
   std::unique_ptr<NetworkingPrivateDelegate> delegate;
 #if BUILDFLAG(IS_CHROMEOS)
   delegate = std::make_unique<NetworkingPrivateChromeOS>(browser_context);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   delegate = std::make_unique<NetworkingPrivateLinux>();
 #elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
   std::unique_ptr<wifi::WiFiService> wifi_service(wifi::WiFiService::Create());
