$NetBSD: patch-services_on__device__model_pre__sandbox__init.cc,v 1.5 2025/08/13 07:44:30 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/on_device_model/pre_sandbox_init.cc.orig	2025-07-29 22:51:44.000000000 +0000
+++ services/on_device_model/pre_sandbox_init.cc
@@ -15,7 +15,7 @@
 #include "services/on_device_model/ml/gpu_blocklist.h"  // nogncheck
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "gpu/config/gpu_info_collector.h"                    // nogncheck
 #endif
 
@@ -29,7 +29,7 @@ namespace on_device_model {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 constexpr uint32_t kVendorIdAMD = 0x1002;
 constexpr uint32_t kVendorIdIntel = 0x8086;
 constexpr uint32_t kVendorIdNVIDIA = 0x10DE;
@@ -63,7 +63,7 @@ void UpdateSandboxOptionsForGpu(
 // enabling the sandbox.
 BASE_FEATURE(kOnDeviceModelWarmDrivers,
              "OnDeviceModelWarmDrivers",
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -132,7 +132,7 @@ bool OnDeviceModelService::PreSandboxIni
   return true;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // static
 void OnDeviceModelService::AddSandboxLinuxOptions(
     sandbox::policy::SandboxLinux::Options& options) {
