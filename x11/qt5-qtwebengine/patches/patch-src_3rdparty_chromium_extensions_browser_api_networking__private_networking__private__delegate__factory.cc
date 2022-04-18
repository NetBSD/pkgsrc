$NetBSD: patch-src_3rdparty_chromium_extensions_browser_api_networking__private_networking__private__delegate__factory.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/extensions/browser/api/networking_private/networking_private_delegate_factory.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/extensions/browser/api/networking_private/networking_private_delegate_factory.cc
@@ -11,7 +11,7 @@
 
 #if defined(OS_CHROMEOS)
 #include "extensions/browser/api/networking_private/networking_private_chromeos.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "extensions/browser/api/networking_private/networking_private_linux.h"
 #elif defined(OS_WIN) || defined(OS_MAC)
 #include "components/wifi/wifi_service.h"
@@ -61,7 +61,7 @@ KeyedService* NetworkingPrivateDelegateF
   NetworkingPrivateDelegate* delegate;
 #if defined(OS_CHROMEOS)
   delegate = new NetworkingPrivateChromeOS(browser_context);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   delegate = new NetworkingPrivateLinux();
 #elif defined(OS_WIN) || defined(OS_MAC)
   std::unique_ptr<wifi::WiFiService> wifi_service(wifi::WiFiService::Create());
