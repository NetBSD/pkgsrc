$NetBSD: patch-sandbox_policy_sandbox__type.cc,v 1.32 2026/11/08 15:39:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- sandbox/policy/sandbox_type.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ sandbox/policy/sandbox_type.cc
@@ -13,7 +13,7 @@
 #include "sandbox/policy/mojom/sandbox.mojom.h"
 #include "sandbox/policy/switches.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "media/gpu/buildflags.h"  // nogncheck
 #include "media/media_buildflags.h"  // nogncheck
 #endif
@@ -35,13 +35,13 @@ constexpr char kServiceSandboxWithJit[] 
 constexpr char kSpeechRecognitionSandbox[] = "speech_recognition";
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 constexpr char kPrintBackendSandbox[] = "print_backend";
 constexpr char kScreenAISandbox[] = "screen_ai";
 constexpr char kPlatformRuntimeSandbox[] = "platform_runtime";
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // The XR Device Service hosts the OpenXR runtime; it is sandboxed on Windows
 // and Linux.
 constexpr char kXrCompositingSandbox[] = "xr_compositing";
@@ -66,11 +66,11 @@ constexpr char kProxyResolverSandbox[] =
 constexpr char kWebNNModelCompilationSandbox[] = "webnn_model_compilation";
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE)
 
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 constexpr char kVideoCaptureSandbox[] = "video_capture";
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 constexpr char kShapeDetectionSandbox[] = "shape_detection";
 // USE_LINUX_VIDEO_ACCELERATION implies IS_LINUX || IS_CHROMEOS, so this double
 // #if is redundant, however, we cannot include "media/gpu/buildflags.h" on all
@@ -90,7 +90,7 @@ constexpr char kTtsSandbox[] = "tts";
 constexpr char kNearbySandbox[] = "nearby";
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 constexpr char kOnDeviceTranslationSandbox[] = "on_device_translation";
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
 
@@ -140,10 +140,10 @@ void SetCommandLineFlagsForSandboxType(b
     case Sandbox::kCdm:
     case Sandbox::kPrintCompositor:
     case Sandbox::kAudio:
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     case Sandbox::kVideoCapture:
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case Sandbox::kXrCompositing:
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
 #if BUILDFLAG(IS_WIN)
@@ -152,7 +152,7 @@ void SetCommandLineFlagsForSandboxType(b
     case Sandbox::kIconReader:
     case Sandbox::kMediaFoundationCdm:
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kShapeDetection:
 #if BUILDFLAG(ENABLE_OOP_VIDEO_DECODER)
     case Sandbox::kHardwareVideoDecoding:
@@ -176,13 +176,13 @@ void SetCommandLineFlagsForSandboxType(b
     case Sandbox::kWebNNModelCompilation:
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE)
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     case Sandbox::kPrintBackend:
     case Sandbox::kScreenAI:
     case Sandbox::kPlatformRuntime:
 #endif
     case Sandbox::kSpeechRecognition:
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kOnDeviceTranslation:
 #endif
       DCHECK(command_line->GetSwitchValueASCII(switches::kProcessType) ==
@@ -192,7 +192,7 @@ void SetCommandLineFlagsForSandboxType(b
           switches::kServiceSandboxType,
           StringFromUtilitySandboxType(sandbox_type));
       return;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kZygoteIntermediateSandbox:
       return;
 #endif
@@ -223,7 +223,7 @@ sandbox::mojom::Sandbox SandboxTypeFromC
     return Sandbox::kGpu;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Intermediate process gains a sandbox later.
   if (process_type == switches::kZygoteProcessType)
     return Sandbox::kZygoteIntermediateSandbox;
@@ -265,7 +265,7 @@ std::string StringFromUtilitySandboxType
       return kUtilitySandbox;
     case Sandbox::kAudio:
       return kAudioSandbox;
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     case Sandbox::kVideoCapture:
       return kVideoCaptureSandbox;
 #endif
@@ -276,7 +276,7 @@ std::string StringFromUtilitySandboxType
     case Sandbox::kSpeechRecognition:
       return kSpeechRecognitionSandbox;
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     case Sandbox::kPrintBackend:
       return kPrintBackendSandbox;
     case Sandbox::kScreenAI:
@@ -284,11 +284,11 @@ std::string StringFromUtilitySandboxType
     case Sandbox::kPlatformRuntime:
       return kPlatformRuntimeSandbox;
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kOnDeviceTranslation:
       return kOnDeviceTranslationSandbox;
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case Sandbox::kXrCompositing:
       return kXrCompositingSandbox;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
@@ -312,7 +312,7 @@ std::string StringFromUtilitySandboxType
     case Sandbox::kWebNNModelCompilation:
       return kWebNNModelCompilationSandbox;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kShapeDetection:
       return kShapeDetectionSandbox;
 #if BUILDFLAG(ENABLE_OOP_VIDEO_DECODER)
@@ -335,7 +335,7 @@ std::string StringFromUtilitySandboxType
       // The following are not utility processes so should not occur.
     case Sandbox::kRenderer:
     case Sandbox::kGpu:
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kZygoteIntermediateSandbox:
 #endif
       NOTREACHED();
@@ -380,7 +380,7 @@ sandbox::mojom::Sandbox UtilitySandboxTy
   if (sandbox_string == kPrintCompositorSandbox) {
     return Sandbox::kPrintCompositor;
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (sandbox_string == kXrCompositingSandbox) {
     return Sandbox::kXrCompositing;
   }
@@ -418,7 +418,7 @@ sandbox::mojom::Sandbox UtilitySandboxTy
     return Sandbox::kSpeechRecognition;
   }
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (sandbox_string == kPrintBackendSandbox) {
     return Sandbox::kPrintBackend;
   }
@@ -429,17 +429,17 @@ sandbox::mojom::Sandbox UtilitySandboxTy
     return Sandbox::kPlatformRuntime;
   }
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (sandbox_string == kOnDeviceTranslationSandbox) {
     return Sandbox::kOnDeviceTranslation;
   }
 #endif
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   if (sandbox_string == kVideoCaptureSandbox) {
     return Sandbox::kVideoCapture;
   }
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (sandbox_string == kShapeDetectionSandbox) {
     return Sandbox::kShapeDetection;
   }
