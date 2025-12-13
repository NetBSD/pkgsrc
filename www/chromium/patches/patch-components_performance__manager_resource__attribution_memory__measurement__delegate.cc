$NetBSD: patch-components_performance__manager_resource__attribution_memory__measurement__delegate.cc,v 1.4 2025/12/13 14:53:54 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/performance_manager/resource_attribution/memory_measurement_delegate.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ components/performance_manager/resource_attribution/memory_measurement_delegate.cc
@@ -100,7 +100,7 @@ void MemoryMeasurementDelegateImpl::OnMe
                 base::KiB(process_dump.os_dump().resident_set_kb),
             .private_footprint =
                 base::KiB(process_dump.os_dump().private_footprint_kb),
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
             // `private_footprint_swap_kb` is only defined on these platforms
             .private_swap =
                 base::KiB(process_dump.os_dump().private_footprint_swap_kb),
