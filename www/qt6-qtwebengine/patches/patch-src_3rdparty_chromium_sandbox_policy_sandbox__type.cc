$NetBSD: patch-src_3rdparty_chromium_sandbox_policy_sandbox__type.cc,v 1.2 2026/04/30 06:39:42 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/sandbox/policy/sandbox_type.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/sandbox/policy/sandbox_type.cc
@@ -16,7 +16,7 @@
 #include "chromeos/ash/components/assistant/buildflags.h"
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "media/gpu/buildflags.h"  // nogncheck
 #include "media/media_buildflags.h"  // nogncheck
 #endif
@@ -38,7 +38,7 @@ constexpr char kServiceSandboxWithJit[] 
 constexpr char kSpeechRecognitionSandbox[] = "speech_recognition";
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 constexpr char kPrintBackendSandbox[] = "print_backend";
 constexpr char kScreenAISandbox[] = "screen_ai";
 #endif
@@ -56,15 +56,15 @@ constexpr char kWindowsSystemProxyResolv
 constexpr char kMirroringSandbox[] = "mirroring";
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kVideoEffectsSandbox[] = "video_effects";
 #endif
 
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 constexpr char kVideoCaptureSandbox[] = "video_capture";
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 constexpr char kShapeDetectionSandbox[] = "shape_detection";
 // USE_LINUX_VIDEO_ACCELERATION implies IS_LINUX || IS_CHROMEOS, so this double
 // #if is redundant, however, we cannot include "media/gpu/buildflags.h" on all
@@ -85,7 +85,7 @@ constexpr char kLibassistantSandbox[] = 
 #endif  // BUILDFLAG(ENABLE_CROS_LIBASSISTANT)
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 constexpr char kOnDeviceTranslationSandbox[] = "on_device_translation";
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
 
@@ -135,7 +135,7 @@ void SetCommandLineFlagsForSandboxType(b
     case Sandbox::kCdm:
     case Sandbox::kPrintCompositor:
     case Sandbox::kAudio:
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     case Sandbox::kVideoCapture:
 #endif
 #if BUILDFLAG(IS_WIN)
@@ -146,7 +146,7 @@ void SetCommandLineFlagsForSandboxType(b
     case Sandbox::kMediaFoundationCdm:
     case Sandbox::kWindowsSystemProxyResolver:
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kShapeDetection:
 #if BUILDFLAG(USE_LINUX_VIDEO_ACCELERATION)
     case Sandbox::kHardwareVideoDecoding:
@@ -165,15 +165,15 @@ void SetCommandLineFlagsForSandboxType(b
     case Sandbox::kMirroring:
 #endif  // BUILDFLAG(IS_MAC)
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     case Sandbox::kPrintBackend:
     case Sandbox::kScreenAI:
 #endif
     case Sandbox::kSpeechRecognition:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case Sandbox::kVideoEffects:
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     case Sandbox::kOnDeviceTranslation:
 #endif
       DCHECK(command_line->GetSwitchValueASCII(switches::kProcessType) ==
@@ -183,7 +183,7 @@ void SetCommandLineFlagsForSandboxType(b
           switches::kServiceSandboxType,
           StringFromUtilitySandboxType(sandbox_type));
       return;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kZygoteIntermediateSandbox:
       return;
 #endif
@@ -214,7 +214,7 @@ sandbox::mojom::Sandbox SandboxTypeFromC
     return Sandbox::kGpu;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Intermediate process gains a sandbox later.
   if (process_type == switches::kZygoteProcessType)
     return Sandbox::kZygoteIntermediateSandbox;
@@ -252,7 +252,7 @@ std::string StringFromUtilitySandboxType
       return kUtilitySandbox;
     case Sandbox::kAudio:
       return kAudioSandbox;
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     case Sandbox::kVideoCapture:
       return kVideoCaptureSandbox;
 #endif
@@ -263,17 +263,17 @@ std::string StringFromUtilitySandboxType
     case Sandbox::kSpeechRecognition:
       return kSpeechRecognitionSandbox;
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     case Sandbox::kPrintBackend:
       return kPrintBackendSandbox;
     case Sandbox::kScreenAI:
       return kScreenAISandbox;
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case Sandbox::kVideoEffects:
       return kVideoEffectsSandbox;
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     case Sandbox::kOnDeviceTranslation:
       return kOnDeviceTranslationSandbox;
 #endif
@@ -293,7 +293,7 @@ std::string StringFromUtilitySandboxType
     case Sandbox::kMirroring:
       return kMirroringSandbox;
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kShapeDetection:
       return kShapeDetectionSandbox;
 #if BUILDFLAG(ALLOW_OOP_VIDEO_DECODER)
@@ -320,7 +320,7 @@ std::string StringFromUtilitySandboxType
       // The following are not utility processes so should not occur.
     case Sandbox::kRenderer:
     case Sandbox::kGpu:
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kZygoteIntermediateSandbox:
 #endif
       NOTREACHED();
@@ -394,7 +394,7 @@ sandbox::mojom::Sandbox UtilitySandboxTy
     return Sandbox::kSpeechRecognition;
   }
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (sandbox_string == kPrintBackendSandbox) {
     return Sandbox::kPrintBackend;
   }
@@ -402,22 +402,22 @@ sandbox::mojom::Sandbox UtilitySandboxTy
     return Sandbox::kScreenAI;
   }
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (sandbox_string == kVideoEffectsSandbox) {
     return Sandbox::kVideoEffects;
   }
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
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
