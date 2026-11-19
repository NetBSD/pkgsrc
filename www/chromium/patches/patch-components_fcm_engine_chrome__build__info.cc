$NetBSD: patch-components_fcm_engine_chrome__build__info.cc,v 1.2 2026/11/19 19:45:58 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/fcm/engine/chrome_build_info.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ components/fcm/engine/chrome_build_info.cc
@@ -27,7 +27,7 @@ ChromePlatform GetPlatform() {
   return ChromePlatform::kAndroid;
 #elif BUILDFLAG(IS_CHROMEOS)
   return ChromePlatform::kCros;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ChromePlatform::kLinux;
 #else
   // For all other platforms, return as LINUX.
