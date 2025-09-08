$NetBSD: patch-components_gcm__driver_gcm__desktop__utils.cc,v 1.5 2025/09/08 13:24:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/gcm_driver/gcm_desktop_utils.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ components/gcm_driver/gcm_desktop_utils.cc
@@ -32,7 +32,7 @@ GCMClient::ChromePlatform GetPlatform() 
   return GCMClient::PLATFORM_ANDROID;
 #elif BUILDFLAG(IS_CHROMEOS)
   return GCMClient::PLATFORM_CROS;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return GCMClient::PLATFORM_LINUX;
 #else
   // For all other platforms, return as LINUX.
