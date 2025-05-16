$NetBSD: patch-components_system__cpu_cpu__probe.cc,v 1.2 2025/05/16 16:08:24 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/system_cpu/cpu_probe.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ components/system_cpu/cpu_probe.cc
@@ -30,6 +30,9 @@ std::unique_ptr<CpuProbe> CpuProbe::Crea
   return CpuProbeWin::Create();
 #elif BUILDFLAG(IS_MAC)
   return CpuProbeMac::Create();
+#elif BUILDFLAG(IS_BSD)
+  NOTIMPLEMENTED();
+  return nullptr;
 #else
   return nullptr;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
