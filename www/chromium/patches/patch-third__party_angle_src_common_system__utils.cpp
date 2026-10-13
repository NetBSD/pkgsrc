$NetBSD: patch-third__party_angle_src_common_system__utils.cpp,v 1.29 2026/10/13 13:16:47 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/angle/src/common/system_utils.cpp.orig	2026-10-06 00:06:58.000000000 +0000
+++ third_party/angle/src/common/system_utils.cpp
@@ -25,7 +25,7 @@ namespace angle
 {
 std::string GetExecutableName()
 {
-#if defined(ANGLE_PLATFORM_ANDROID) && __ANDROID_API__ >= 21
+#if (defined(ANGLE_PLATFORM_ANDROID) && __ANDROID_API__ >= 21) || defined(ANGLE_PLATFORM_BSD)
     // Support for "getprogname" function in bionic was introduced in L (API level 21)
     const char *executableName = getprogname();
     return (executableName) ? std::string(executableName) : "ANGLE";
