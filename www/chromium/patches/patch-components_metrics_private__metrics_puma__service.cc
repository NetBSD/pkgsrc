$NetBSD: patch-components_metrics_private__metrics_puma__service.cc,v 1.2 2026/02/15 09:04:03 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/metrics/private_metrics/puma_service.cc.orig	2026-02-03 22:07:10.000000000 +0000
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
