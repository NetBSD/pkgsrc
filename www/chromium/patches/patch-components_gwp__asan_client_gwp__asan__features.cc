$NetBSD: patch-components_gwp__asan_client_gwp__asan__features.cc,v 1.15 2026/02/15 09:04:03 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/gwp_asan/client/gwp_asan_features.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ components/gwp_asan/client/gwp_asan_features.cc
@@ -9,7 +9,7 @@
 namespace gwp_asan::internal {
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) ||                                          \
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD) ||                     \
     (BUILDFLAG(IS_ANDROID) && defined(ARCH_CPU_64_BITS))
 constexpr base::FeatureState kDefaultEnabled = base::FEATURE_ENABLED_BY_DEFAULT;
 #else
@@ -72,7 +72,7 @@ GWP_ASAN_EXPORT extern const base::Featu
     kGwpAsanMallocGpuAllocationSamplingRange{&kGwpAsanMalloc,
                                              "GpuAllocationSamplingRange", 16};
 
-#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 // Browser reservation params.
 GWP_ASAN_EXPORT extern const base::FeatureParam<int>
