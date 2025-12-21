$NetBSD: patch-src_3rdparty_chromium_services_on__device__model_on__device__model__service.h,v 1.1 2025/12/21 09:38:38 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/services/on_device_model/on_device_model_service.h.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/services/on_device_model/on_device_model_service.h
@@ -31,6 +31,10 @@ class OnDeviceModelInternalImpl;
 class TsHolder;
 }
 
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#endif
+
 namespace on_device_model {
 
 class COMPONENT_EXPORT(ON_DEVICE_MODEL) OnDeviceModelService
@@ -44,7 +48,7 @@ class COMPONENT_EXPORT(ON_DEVICE_MODEL) 
   // Must be called in the service's process after the run loop finished.
   [[nodiscard]] static bool Shutdown();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static void AddSandboxLinuxOptions(
       sandbox::policy::SandboxLinux::Options& options);
 #endif
