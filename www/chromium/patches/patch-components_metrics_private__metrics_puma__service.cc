$NetBSD: patch-components_metrics_private__metrics_puma__service.cc,v 1.3 2026/03/14 12:40:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/metrics/private_metrics/puma_service.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ components/metrics/private_metrics/puma_service.cc
@@ -71,7 +71,7 @@ Platform GetCurrentPlatform() {
   return Platform::PLATFORM_WINDOWS;
 #elif BUILDFLAG(IS_MAC)
   return Platform::PLATFORM_MACOS;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return Platform::PLATFORM_LINUX;
 #elif BUILDFLAG(IS_ANDROID)
   // TODO(b/463580425): Differentiate between Android platforms.
