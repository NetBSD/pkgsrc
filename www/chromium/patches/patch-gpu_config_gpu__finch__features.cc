$NetBSD: patch-gpu_config_gpu__finch__features.cc,v 1.24 2026/08/09 06:31:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/config/gpu_finch_features.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ gpu/config/gpu_finch_features.cc
@@ -176,7 +176,7 @@ const base::FeatureParam<std::string>
 // of associating with an unused IPC::Channel.
 BASE_FEATURE(kRemoveGPULegacyIPC, base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Feature flag to control whether SharedImageStub sequence uses high priority
 // on ChromeOS and Linux. Enabled by default.
 BASE_FEATURE(kSharedImageStubHighPriority, base::FEATURE_DISABLED_BY_DEFAULT);
@@ -185,7 +185,7 @@ BASE_FEATURE(kSharedImageStubHighPriorit
 // Disables hardware YUV conversion on NVIDIA + Wayland to workaround a driver
 // bug.
 BASE_FEATURE(kNvidiaWaylandYuvHardwareConversionWorkaround,
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -515,7 +515,7 @@ BASE_FEATURE(kGPUDriverBugListTestGroup,
 const base::FeatureParam<int> kGPUDriverBugListTestGroupId{
     &kGPUDriverBugListTestGroup, "test_group", 0};
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool IsForceEnableWebGpuInterop() {
   return base::FeatureList::IsEnabled(kForceEnableWebGpuInterop);
 }
