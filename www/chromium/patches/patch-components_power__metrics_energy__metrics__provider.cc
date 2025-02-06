$NetBSD: patch-components_power__metrics_energy__metrics__provider.cc,v 1.1 2025/02/06 09:58:02 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/power_metrics/energy_metrics_provider.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ components/power_metrics/energy_metrics_provider.cc
@@ -9,6 +9,8 @@
 #include "components/power_metrics/energy_metrics_provider_win.h"
 #elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 #include "components/power_metrics/energy_metrics_provider_linux.h"
+#elif BUILDFLAG(IS_BSD)
+#include "base/notreached.h"
 #endif  // BUILDFLAG(IS_WIN)
 
 namespace power_metrics {
@@ -22,6 +24,9 @@ std::unique_ptr<EnergyMetricsProvider> E
   return EnergyMetricsProviderWin::Create();
 #elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
   return EnergyMetricsProviderLinux::Create();
+#elif BUILDFLAG(IS_BSD)
+  NOTIMPLEMENTED();
+  return nullptr;
 #else
   return nullptr;
 #endif  // BUILDFLAG(IS_WIN)
