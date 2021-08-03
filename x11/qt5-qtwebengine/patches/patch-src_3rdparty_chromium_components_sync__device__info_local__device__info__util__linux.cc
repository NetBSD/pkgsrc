$NetBSD: patch-src_3rdparty_chromium_components_sync__device__info_local__device__info__util__linux.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/components/sync_device_info/local_device_info_util_linux.cc.orig	2020-07-15 18:55:55.000000000 +0000
+++ src/3rdparty/chromium/components/sync_device_info/local_device_info_util_linux.cc
@@ -36,6 +36,12 @@ std::string GetChromeOSDeviceNameFromTyp
 std::string GetPersonalizableDeviceNameInternal() {
 #if defined(OS_CHROMEOS)
   return GetChromeOSDeviceNameFromType();
+#elif defined(__NetBSD__)
+  int len = sysconf(_SC_HOST_NAME_MAX);
+  char hostname[len];
+  if (gethostname(hostname, _SC_HOST_NAME_MAX) == 0)  // Success.
+    return hostname;
+  return base::GetLinuxDistro();
 #else
   char hostname[HOST_NAME_MAX];
   if (gethostname(hostname, HOST_NAME_MAX) == 0)  // Success.
