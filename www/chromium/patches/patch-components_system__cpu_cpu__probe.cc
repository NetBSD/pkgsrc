$NetBSD: patch-components_system__cpu_cpu__probe.cc,v 1.1 2025/02/06 09:58:03 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/system_cpu/cpu_probe.cc.orig	2024-12-17 17:58:49.000000000 +0000
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
