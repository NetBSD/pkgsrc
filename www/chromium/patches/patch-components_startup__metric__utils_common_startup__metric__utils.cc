$NetBSD: patch-components_startup__metric__utils_common_startup__metric__utils.cc,v 1.19 2026/05/10 15:29:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/startup_metric_utils/common/startup_metric_utils.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ components/startup_metric_utils/common/startup_metric_utils.cc
@@ -95,7 +95,7 @@ base::TimeTicks CommonStartupMetricRecor
   // Enabling this logic on OS X causes a significant performance regression.
   // TODO(crbug.com/40464036): Remove IS_APPLE ifdef once utility processes
   // set their desired main thread priority.
-#if !BUILDFLAG(IS_APPLE)
+#if !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
   static bool statics_initialized = false;
   if (!statics_initialized) {
     statics_initialized = true;
