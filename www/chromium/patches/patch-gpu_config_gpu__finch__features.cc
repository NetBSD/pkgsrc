$NetBSD: patch-gpu_config_gpu__finch__features.cc,v 1.23 2026/07/08 13:42:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/config/gpu_finch_features.cc.orig	2026-07-06 22:58:46.000000000 +0000
+++ gpu/config/gpu_finch_features.cc
@@ -111,7 +111,7 @@ const base::FeatureParam<std::string>
 // of associating with an unused IPC::Channel.
 BASE_FEATURE(kRemoveGPULegacyIPC, base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Feature flag to control whether SharedImageStub sequence uses high priority
 // on ChromeOS and Linux. Enabled by default.
 BASE_FEATURE(kSharedImageStubHighPriority, base::FEATURE_DISABLED_BY_DEFAULT);
@@ -120,7 +120,7 @@ BASE_FEATURE(kSharedImageStubHighPriorit
 // Disables hardware YUV conversion on NVIDIA + Wayland to workaround a driver
 // bug.
 BASE_FEATURE(kNvidiaWaylandYuvHardwareConversionWorkaround,
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -449,7 +449,7 @@ BASE_FEATURE(kGPUDriverBugListTestGroup,
 const base::FeatureParam<int> kGPUDriverBugListTestGroupId{
     &kGPUDriverBugListTestGroup, "test_group", 0};
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool IsForceEnableWebGpuInterop() {
   return base::FeatureList::IsEnabled(kForceEnableWebGpuInterop);
 }
