$NetBSD: patch-components_power__metrics_energy__metrics__provider.cc,v 1.26 2026/09/22 13:41:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/power_metrics/energy_metrics_provider.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ components/power_metrics/energy_metrics_provider.cc
@@ -7,7 +7,7 @@
 #include "build/build_config.h"
 #if BUILDFLAG(IS_WIN)
 #include "components/power_metrics/energy_metrics_provider_win.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/power_metrics/energy_metrics_provider_linux.h"
 #endif  // BUILDFLAG(IS_WIN)
 
@@ -20,7 +20,7 @@ EnergyMetricsProvider::~EnergyMetricsPro
 std::unique_ptr<EnergyMetricsProvider> EnergyMetricsProvider::Create() {
 #if BUILDFLAG(IS_WIN)
   return EnergyMetricsProviderWin::Create();
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return EnergyMetricsProviderLinux::Create();
 #else
   return nullptr;
