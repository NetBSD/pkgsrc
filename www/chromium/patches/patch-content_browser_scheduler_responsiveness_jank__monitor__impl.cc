$NetBSD: patch-content_browser_scheduler_responsiveness_jank__monitor__impl.cc,v 1.1 2025/02/06 09:58:06 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/scheduler/responsiveness/jank_monitor_impl.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ content/browser/scheduler/responsiveness/jank_monitor_impl.cc
@@ -340,7 +340,7 @@ void JankMonitorImpl::ThreadExecutionSta
     // in context menus, among others). Simply ignore the mismatches for now.
     // See https://crbug.com/929813 for the details of why the mismatch
     // happens.
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)) && \
     BUILDFLAG(IS_OZONE)
     task_execution_metadata_.clear();
 #endif
