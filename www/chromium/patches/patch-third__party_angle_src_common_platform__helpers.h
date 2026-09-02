$NetBSD: patch-third__party_angle_src_common_platform__helpers.h,v 1.25 2026/09/02 13:13:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/angle/src/common/platform_helpers.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ third_party/angle/src/common/platform_helpers.h
@@ -62,7 +62,7 @@ inline constexpr bool IsIOS()
 
 inline constexpr bool IsLinux()
 {
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
     return true;
 #else
     return false;
