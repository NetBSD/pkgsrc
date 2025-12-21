$NetBSD: patch-src_3rdparty_chromium_third__party_angle_src_common_system__utils.cpp,v 1.1 2025/12/21 09:38:39 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/angle/src/common/system_utils.cpp.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/third_party/angle/src/common/system_utils.cpp
@@ -25,7 +25,7 @@ namespace angle
 {
 std::string GetExecutableName()
 {
-#if defined(ANGLE_PLATFORM_ANDROID) && __ANDROID_API__ >= 21
+#if (defined(ANGLE_PLATFORM_ANDROID) && __ANDROID_API__ >= 21) || defined(ANGLE_PLATFORM_BSD)
     // Support for "getprogname" function in bionic was introduced in L (API level 21)
     const char *executableName = getprogname();
     return (executableName) ? std::string(executableName) : "ANGLE";
