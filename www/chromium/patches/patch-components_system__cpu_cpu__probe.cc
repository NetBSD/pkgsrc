$NetBSD: patch-components_system__cpu_cpu__probe.cc,v 1.14 2026/01/19 16:14:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/system_cpu/cpu_probe.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ components/system_cpu/cpu_probe.cc
@@ -20,6 +20,10 @@
 #include "components/system_cpu/cpu_probe_mac.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
+#if BUILDFLAG(IS_BSD)
+#include "base/notimplemented.h"
+#endif
+
 namespace system_cpu {
 
 // static
@@ -30,6 +34,9 @@ std::unique_ptr<CpuProbe> CpuProbe::Crea
   return CpuProbeWin::Create();
 #elif BUILDFLAG(IS_MAC)
   return CpuProbeMac::Create();
+#elif BUILDFLAG(IS_BSD)
+  NOTIMPLEMENTED();
+  return nullptr;
 #else
   return nullptr;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
