$NetBSD: patch-components_variations_service_variations__service.cc,v 1.14 2026/01/19 16:14:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/variations/service/variations_service.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ components/variations/service/variations_service.cc
@@ -100,7 +100,7 @@ std::string GetPlatformString() {
   return "android";
 #elif BUILDFLAG(IS_FUCHSIA)
   return "fuchsia";
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || BUILDFLAG(IS_SOLARIS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || BUILDFLAG(IS_SOLARIS) || BUILDFLAG(IS_BSD)
   // Default BSD and SOLARIS to Linux to not break those builds, although these
   // platforms are not officially supported by Chrome.
   return "linux";
