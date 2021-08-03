$NetBSD: patch-src_3rdparty_chromium_third__party_angle_src_libANGLE_renderer_driver__utils.cpp,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/third_party/angle/src/libANGLE/renderer/driver_utils.cpp.orig	2020-07-15 19:01:32.000000000 +0000
+++ src/3rdparty/chromium/third_party/angle/src/libANGLE/renderer/driver_utils.cpp
@@ -16,7 +18,7 @@
 #    include <sys/system_properties.h>
 #endif
 
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
 #    include <sys/utsname.h>
 #endif
 
@@ -206,12 +208,20 @@ OSVersion GetMacOSVersion()
 }
 #endif
 
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
 bool ParseLinuxOSVersion(const char *version, int *major, int *minor, int *patch)
 {
     errno = 0;  // reset global error flag.
     char *next;
     *major = static_cast<int>(strtol(version, &next, 10));
+#if defined(OS_BSD)
+    if (next == nullptr || *next != '-' || errno != 0)
+    {
+        return false;
+    }
+
+    *patch = 0;
+#else
     if (next == nullptr || *next != '.' || errno != 0)
     {
         return false;
@@ -228,6 +238,7 @@ bool ParseLinuxOSVersion(const char *ver
     {
         return false;
     }
+#endif
 
     return true;
 }
@@ -235,7 +246,7 @@ bool ParseLinuxOSVersion(const char *ver
 
 OSVersion GetLinuxOSVersion()
 {
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
     struct utsname uname_info;
     if (uname(&uname_info) != 0)
     {
