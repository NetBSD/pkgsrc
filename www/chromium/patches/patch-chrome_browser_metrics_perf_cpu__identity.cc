$NetBSD: patch-chrome_browser_metrics_perf_cpu__identity.cc,v 1.1 2025/02/06 09:57:49 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/metrics/perf/cpu_identity.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/metrics/perf/cpu_identity.cc
@@ -147,7 +147,7 @@ CPUIdentity GetCPUIdentity() {
   result.release =
 #if BUILDFLAG(IS_CHROMEOS_ASH)
       base::SysInfo::KernelVersion();
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
       base::SysInfo::OperatingSystemVersion();
 #else
 #error "Unsupported configuration"
