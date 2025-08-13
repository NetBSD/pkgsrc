$NetBSD: patch-services_on__device__model_on__device__model__service.h,v 1.5 2025/08/13 07:44:30 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/on_device_model/on_device_model_service.h.orig	2025-07-29 22:51:44.000000000 +0000
+++ services/on_device_model/on_device_model_service.h
@@ -31,6 +31,10 @@ class OnDeviceModelInternalImpl;
 class TsHolder;
 }
 
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#endif
+
 namespace on_device_model {
 
 inline constexpr base::TimeDelta kDefaultModelIdleTimeout = base::Minutes(5);
@@ -46,7 +50,7 @@ class COMPONENT_EXPORT(ON_DEVICE_MODEL) 
   // Must be called in the service's process after the run loop finished.
   [[nodiscard]] static bool Shutdown();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static void AddSandboxLinuxOptions(
       sandbox::policy::SandboxLinux::Options& options);
 #endif
