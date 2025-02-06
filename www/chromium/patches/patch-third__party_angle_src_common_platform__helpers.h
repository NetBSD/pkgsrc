$NetBSD: patch-third__party_angle_src_common_platform__helpers.h,v 1.1 2025/02/06 09:58:22 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/angle/src/common/platform_helpers.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/angle/src/common/platform_helpers.h
@@ -62,7 +62,7 @@ inline constexpr bool IsIOS()
 
 inline constexpr bool IsLinux()
 {
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
     return true;
 #else
     return false;
