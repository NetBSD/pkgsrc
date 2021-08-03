$NetBSD: patch-src_3rdparty_chromium_chrome_browser_extensions_api_enterprise__reporting__private_device__info__fetcher.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/chrome/browser/extensions/api/enterprise_reporting_private/device_info_fetcher.cc.orig	2020-07-08 21:41:46.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/extensions/api/enterprise_reporting_private/device_info_fetcher.cc
@@ -10,7 +10,7 @@
 #include "chrome/browser/extensions/api/enterprise_reporting_private/device_info_fetcher_mac.h"
 #elif defined(OS_WIN)
 #include "chrome/browser/extensions/api/enterprise_reporting_private/device_info_fetcher_win.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/extensions/api/enterprise_reporting_private/device_info_fetcher_linux.h"
 #endif
 
@@ -57,7 +57,7 @@ std::unique_ptr<DeviceInfoFetcher> Devic
   return std::make_unique<DeviceInfoFetcherMac>();
 #elif defined(OS_WIN)
   return std::make_unique<DeviceInfoFetcherWin>();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return std::make_unique<DeviceInfoFetcherLinux>();
 #else
   return std::make_unique<StubDeviceFetcher>();
