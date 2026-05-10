$NetBSD: patch-components_performance__manager_resource__attribution_memory__measurement__delegate.cc,v 1.11 2026/05/10 15:29:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/performance_manager/resource_attribution/memory_measurement_delegate.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ components/performance_manager/resource_attribution/memory_measurement_delegate.cc
@@ -100,7 +100,7 @@ void MemoryMeasurementDelegateImpl::OnMe
                 base::KiBU(process_dump.os_dump().resident_set_kb),
             .private_footprint =
                 base::KiBU(process_dump.os_dump().private_footprint_kb),
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
             // `private_footprint_swap_kb` is only defined on these platforms
             .private_swap =
                 base::KiBU(process_dump.os_dump().private_footprint_swap_kb),
