$NetBSD: patch-src_3rdparty_chromium_chrome_browser_extensions_api_enterprise__reporting__private_device__info__fetcher__linux.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/chrome/browser/extensions/api/enterprise_reporting_private/device_info_fetcher_linux.cc.orig	2020-07-24 02:37:46.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/extensions/api/enterprise_reporting_private/device_info_fetcher_linux.cc
@@ -8,7 +8,9 @@
 #include <gio/gio.h>
 #endif  // defined(USE_GIO)
 #include <sys/stat.h>
+#if defined(OS_LINUX)
 #include <sys/sysmacros.h>
+#endif
 
 #include <string>
 
@@ -91,6 +93,7 @@ enterprise_reporting_private::SettingVal
 // Implements the logic from the native host installation script. First find the
 // root device identifier, then locate its parent and get its type.
 enterprise_reporting_private::SettingValue GetDiskEncrypted() {
+#if !defined(OS_BSD)
   struct stat info;
   // First figure out the device identifier.
   stat("/", &info);
@@ -110,6 +113,7 @@ enterprise_reporting_private::SettingVal
     return is_encrypted ? enterprise_reporting_private::SETTING_VALUE_ENABLED
                         : enterprise_reporting_private::SETTING_VALUE_DISABLED;
   }
+#endif
   return enterprise_reporting_private::SETTING_VALUE_UNKNOWN;
 }
 
@@ -121,7 +125,11 @@ DeviceInfoFetcherLinux::~DeviceInfoFetch
 
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
