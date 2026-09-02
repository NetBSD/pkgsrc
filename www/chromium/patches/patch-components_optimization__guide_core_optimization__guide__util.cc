$NetBSD: patch-components_optimization__guide_core_optimization__guide__util.cc,v 1.25 2026/09/02 13:13:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/optimization_guide/core/optimization_guide_util.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ components/optimization_guide/core/optimization_guide_util.cc
@@ -37,7 +37,7 @@ optimization_guide::proto::Platform GetP
   return optimization_guide::proto::PLATFORM_CHROMEOS;
 #elif BUILDFLAG(IS_ANDROID)
   return optimization_guide::proto::PLATFORM_ANDROID;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return optimization_guide::proto::PLATFORM_LINUX;
 #else
   return optimization_guide::proto::PLATFORM_UNDEFINED;
@@ -195,7 +195,7 @@ optimization_guide::proto::ChromePlatfor
   return optimization_guide::proto::CHROME_PLATFORM_CHROMEOS;
 #elif BUILDFLAG(IS_ANDROID)
   return optimization_guide::proto::CHROME_PLATFORM_ANDROID;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return optimization_guide::proto::CHROME_PLATFORM_LINUX;
 #else
   return optimization_guide::proto::CHROME_PLATFORM_UNKNOWN;
