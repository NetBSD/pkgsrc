$NetBSD: patch-content_utility_services.cc,v 1.7 2025/09/12 16:02:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/utility/services.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ content/utility/services.cc
@@ -74,13 +74,13 @@
 extern sandbox::TargetServices* g_utility_target_services;
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "sandbox/linux/services/libc_interceptor.h"
 #include "sandbox/policy/mojom/sandbox.mojom.h"
 #include "sandbox/policy/sandbox_type.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(GOOGLE_CHROME_BRANDING) && (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX))
+#if BUILDFLAG(GOOGLE_CHROME_BRANDING) && (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 #include "services/shape_detection/public/mojom/shape_detection_service.mojom.h"  // nogncheck
 #include "services/shape_detection/shape_detection_service.h"  // nogncheck
 #endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING) && BUILDFLAG(IS_CHROMEOS)
@@ -235,7 +235,7 @@ auto RunAudio(mojo::PendingReceiver<audi
       << "task_policy_set TASK_QOS_POLICY";
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   auto* command_line = base::CommandLine::ForCurrentProcess();
   if (sandbox::policy::SandboxTypeFromCommandLine(*command_line) ==
       sandbox::mojom::Sandbox::kNoSandbox) {
@@ -257,7 +257,7 @@ auto RunAudio(mojo::PendingReceiver<audi
   return audio::CreateStandaloneService(std::move(receiver));
 }
 
-#if BUILDFLAG(GOOGLE_CHROME_BRANDING) && (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX))
+#if BUILDFLAG(GOOGLE_CHROME_BRANDING) && (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 auto RunShapeDetectionService(
     mojo::PendingReceiver<shape_detection::mojom::ShapeDetectionService>
         receiver) {
@@ -432,7 +432,7 @@ void RegisterMainThreadServices(mojo::Se
     services.Add(RunOnDeviceModel);
   }
 
-#if BUILDFLAG(GOOGLE_CHROME_BRANDING) && (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX))
+#if BUILDFLAG(GOOGLE_CHROME_BRANDING) && (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   services.Add(RunShapeDetectionService);
 #endif
 
