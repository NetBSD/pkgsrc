$NetBSD: patch-components_gwp__asan_client_gwp__asan.cc,v 1.7 2025/09/12 16:02:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/gwp_asan/client/gwp_asan.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ components/gwp_asan/client/gwp_asan.cc
@@ -81,7 +81,7 @@ namespace {
 // ProcessSamplingBoost is the multiplier to increase the
 // ProcessSamplingProbability in scenarios where we want to perform additional
 // testing (e.g., on canary/dev builds).
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 constexpr int kDefaultMaxAllocations = 50;
 constexpr int kDefaultMaxMetadata = 210;
 constexpr int kDefaultTotalPages = kCpuIs64Bit ? 2048 : kDefaultMaxMetadata * 2;
