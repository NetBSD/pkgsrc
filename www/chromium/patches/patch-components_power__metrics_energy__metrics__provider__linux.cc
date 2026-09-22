$NetBSD: patch-components_power__metrics_energy__metrics__provider__linux.cc,v 1.1 2026/09/22 13:41:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/power_metrics/energy_metrics_provider_linux.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ components/power_metrics/energy_metrics_provider_linux.cc
@@ -5,8 +5,10 @@
 
 #include "components/power_metrics/energy_metrics_provider_linux.h"
 
+#if !BUILDFLAG(IS_BSD)
 #include <linux/perf_event.h>
 #include <sys/syscall.h>
+#endif
 
 #include <array>
 
@@ -26,6 +28,7 @@ namespace {
 
 constexpr const char* kPowerEventPath = "/sys/bus/event_source/devices/power";
 
+#if !BUILDFLAG(IS_BSD)
 // Existing metrics that can be read via perf event.
 constexpr std::array<const char*, 5> kMetrics{
     "energy-pkg", "energy-cores", "energy-gpu", "energy-ram", "energy-psys"};
@@ -84,6 +87,7 @@ void SetEnergyMetric(const std::string& 
     energy_metrics.psys_nanojoules = absolute_energy;
   }
 }
+#endif
 
 }  // namespace
 
@@ -115,6 +119,7 @@ EnergyMetricsProviderLinux::CaptureMetri
   }
 
   EnergyMetrics energy_metrics = {0};
+#if !BUILDFLAG(IS_BSD)
   for (const auto& event : events_) {
     uint64_t absolute_energy;
     if (!base::ReadFromFD(
@@ -126,6 +131,7 @@ EnergyMetricsProviderLinux::CaptureMetri
     SetEnergyMetric(event.metric_type, energy_metrics,
                     static_cast<uint64_t>(event.scale * absolute_energy));
   }
+#endif
   return energy_metrics;
 }
 
@@ -145,6 +151,7 @@ bool EnergyMetricsProviderLinux::Initial
     return false;
   }
 
+#if !BUILDFLAG(IS_BSD)
   // Check if perf_event_paranoid is set to 0 as required.
   uint64_t perf_event_paranoid;
   if (!ReadUint64FromFile(
@@ -208,6 +215,7 @@ bool EnergyMetricsProviderLinux::Initial
     }
     events_.push_back({metric, scale, std::move(fd)});
   }
+#endif
 
   if (events_.empty()) {
     LOG(WARNING) << "No available energy metric";
