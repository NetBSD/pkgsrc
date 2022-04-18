$NetBSD: patch-src_3rdparty_chromium_chrome_browser_extensions_api_enterprise__reporting__private_device__info__fetcher__linux.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/chrome/browser/extensions/api/enterprise_reporting_private/device_info_fetcher_linux.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/extensions/api/enterprise_reporting_private/device_info_fetcher_linux.cc
@@ -8,7 +8,9 @@
 #include <gio/gio.h>
 #endif  // defined(USE_GIO)
 #include <sys/stat.h>
+#if defined(OS_LINUX)
 #include <sys/sysmacros.h>
+#endif
 
 #include <string>
 
@@ -107,6 +109,7 @@ enterprise_reporting_private::SettingVal
 // Implements the logic from the native host installation script. First find the
 // root device identifier, then locate its parent and get its type.
 enterprise_reporting_private::SettingValue GetDiskEncrypted() {
+#if !defined(OS_BSD)
   struct stat info;
   // First figure out the device identifier. Fail fast if this fails.
   if (stat("/", &info) != 0)
@@ -130,6 +133,7 @@ enterprise_reporting_private::SettingVal
     }
     return enterprise_reporting_private::SETTING_VALUE_UNKNOWN;
   }
+#endif
   return enterprise_reporting_private::SETTING_VALUE_DISABLED;
 }
 
@@ -168,7 +172,11 @@ DeviceInfoFetcherLinux::~DeviceInfoFetch
 
 DeviceInfo DeviceInfoFetcherLinux::Fetch() {
   DeviceInfo device_info;
+#if defined(OS_NETBSD)
+  device_info.os_name = "netbsd";
+#else
   device_info.os_name = "linux";
+#endif
   device_info.os_version = GetOsVersion();
   device_info.device_host_name = GetDeviceHostName();
   device_info.device_model = GetDeviceModel();
