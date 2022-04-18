$NetBSD: patch-src_3rdparty_chromium_chrome_browser_extensions_api_enterprise__reporting__private_device__info__fetcher.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/chrome/browser/extensions/api/enterprise_reporting_private/device_info_fetcher.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/extensions/api/enterprise_reporting_private/device_info_fetcher.cc
@@ -10,7 +10,7 @@
 #include "chrome/browser/extensions/api/enterprise_reporting_private/device_info_fetcher_mac.h"
 #elif defined(OS_WIN)
 #include "chrome/browser/extensions/api/enterprise_reporting_private/device_info_fetcher_win.h"
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "chrome/browser/extensions/api/enterprise_reporting_private/device_info_fetcher_linux.h"
 #endif
 
@@ -58,7 +58,7 @@ std::unique_ptr<DeviceInfoFetcher> Devic
   return std::make_unique<DeviceInfoFetcherMac>();
 #elif defined(OS_WIN)
   return std::make_unique<DeviceInfoFetcherWin>();
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   return std::make_unique<DeviceInfoFetcherLinux>();
 #else
   return std::make_unique<StubDeviceFetcher>();
