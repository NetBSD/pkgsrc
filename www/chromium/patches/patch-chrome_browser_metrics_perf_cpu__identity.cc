$NetBSD: patch-chrome_browser_metrics_perf_cpu__identity.cc,v 1.5 2025/08/13 07:44:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/metrics/perf/cpu_identity.cc.orig	2025-07-29 22:51:44.000000000 +0000
+++ chrome/browser/metrics/perf/cpu_identity.cc
@@ -146,7 +146,7 @@ CPUIdentity GetCPUIdentity() {
   result.release =
 #if BUILDFLAG(IS_CHROMEOS)
       base::SysInfo::KernelVersion();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::SysInfo::OperatingSystemVersion();
 #else
 #error "Unsupported configuration"
