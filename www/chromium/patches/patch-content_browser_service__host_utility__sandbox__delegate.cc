$NetBSD: patch-content_browser_service__host_utility__sandbox__delegate.cc,v 1.13 2026/01/19 16:14:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/service_host/utility_sandbox_delegate.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ content/browser/service_host/utility_sandbox_delegate.cc
@@ -24,7 +24,7 @@
 #include "sandbox/policy/sandbox_type.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "media/gpu/buildflags.h"
 #include "media/media_buildflags.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -72,10 +72,10 @@ UtilitySandboxedProcessLauncherDelegate:
       sandbox_type_ == sandbox::mojom::Sandbox::kOnDeviceModelExecution ||
       sandbox_type_ == sandbox::mojom::Sandbox::kCdm ||
       sandbox_type_ == sandbox::mojom::Sandbox::kPrintCompositor ||
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kVideoCapture ||
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kShapeDetection ||
 #if BUILDFLAG(ALLOW_OOP_VIDEO_DECODER)
       sandbox_type_ == sandbox::mojom::Sandbox::kHardwareVideoDecoding ||
@@ -90,11 +90,11 @@ UtilitySandboxedProcessLauncherDelegate:
       sandbox_type_ == sandbox::mojom::Sandbox::kNearby ||
 #endif  // BUILDFLAG(IS_CHROMEOS)
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kScreenAI ||
       sandbox_type_ == sandbox::mojom::Sandbox::kPrintBackend ||
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kOnDeviceTranslation ||
 #endif
       sandbox_type_ == sandbox::mojom::Sandbox::kAudio ||
@@ -151,15 +151,15 @@ ZygoteCommunication* UtilitySandboxedPro
       sandbox_type_ == sandbox::mojom::Sandbox::kNearby ||
 #endif  // BUILDFLAG(IS_CHROMEOS)
       sandbox_type_ == sandbox::mojom::Sandbox::kAudio ||
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kShapeDetection ||
 #endif
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kPrintBackend ||
       sandbox_type_ == sandbox::mojom::Sandbox::kScreenAI ||
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kOnDeviceTranslation ||
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
       sandbox_type_ == sandbox::mojom::Sandbox::kSpeechRecognition) {
