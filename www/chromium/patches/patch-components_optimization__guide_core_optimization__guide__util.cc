$NetBSD: patch-components_optimization__guide_core_optimization__guide__util.cc,v 1.14 2026/01/19 16:14:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/optimization_guide/core/optimization_guide_util.cc.orig	2026-01-07 00:50:30.000000000 +0000
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
