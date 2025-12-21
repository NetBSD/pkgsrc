$NetBSD: patch-src_3rdparty_chromium_components_gwp__asan_client_gwp__asan__features.cc,v 1.1 2025/12/21 09:38:22 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/gwp_asan/client/gwp_asan_features.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/components/gwp_asan/client/gwp_asan_features.cc
@@ -9,7 +9,7 @@
 namespace gwp_asan::internal {
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) ||                                          \
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD) ||                     \
     (BUILDFLAG(IS_ANDROID) && defined(ARCH_CPU_64_BITS))
 constexpr base::FeatureState kDefaultEnabled = base::FEATURE_ENABLED_BY_DEFAULT;
 #else
