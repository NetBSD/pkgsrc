$NetBSD: patch-components_startup__metric__utils_common_startup__metric__utils.cc,v 1.1 2025/02/06 09:58:03 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/startup_metric_utils/common/startup_metric_utils.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ components/startup_metric_utils/common/startup_metric_utils.cc
@@ -94,7 +94,7 @@ base::TimeTicks CommonStartupMetricRecor
   // Enabling this logic on OS X causes a significant performance regression.
   // TODO(crbug.com/40464036): Remove IS_APPLE ifdef once utility processes
   // set their desired main thread priority.
-#if !BUILDFLAG(IS_APPLE)
+#if !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
   static bool statics_initialized = false;
   if (!statics_initialized) {
     statics_initialized = true;
