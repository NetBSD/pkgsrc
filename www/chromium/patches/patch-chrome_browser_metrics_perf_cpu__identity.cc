$NetBSD: patch-chrome_browser_metrics_perf_cpu__identity.cc,v 1.30 2026/10/16 15:30:45 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/metrics/perf/cpu_identity.cc.orig	2026-10-14 21:09:54.000000000 +0000
+++ chrome/browser/metrics/perf/cpu_identity.cc
@@ -155,7 +155,7 @@ CPUIdentity GetCPUIdentity() {
   result.release =
 #if BUILDFLAG(IS_CHROMEOS)
       base::SysInfo::KernelVersion();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::SysInfo::OperatingSystemVersion();
 #else
 #error "Unsupported configuration"
