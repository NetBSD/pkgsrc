$NetBSD: patch-sandbox_policy_sandbox__type.cc,v 1.1 2025/02/06 09:58:19 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- sandbox/policy/sandbox_type.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ sandbox/policy/sandbox_type.cc
@@ -38,7 +38,7 @@ bool IsUnsandboxedSandboxType(Sandbox sa
 #endif
     case Sandbox::kAudio:
       return false;
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     case Sandbox::kVideoCapture:
       return false;
 #endif
@@ -62,7 +62,7 @@ bool IsUnsandboxedSandboxType(Sandbox sa
 #if BUILDFLAG(IS_MAC)
     case Sandbox::kMirroring:
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
     case Sandbox::kHardwareVideoDecoding:
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
 #if BUILDFLAG(IS_CHROMEOS_ASH)
@@ -73,7 +73,7 @@ bool IsUnsandboxedSandboxType(Sandbox sa
     case Sandbox::kLibassistant:
 #endif  // BUILDFLAG(ENABLE_CROS_LIBASSISTANT)
 #endif  // // BUILDFLAG(IS_CHROMEOS_ASH)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) | BUILDFLAG(IS_BSD)
     case Sandbox::kZygoteIntermediateSandbox:
     case Sandbox::kHardwareVideoEncoding:
 #endif
@@ -81,10 +81,10 @@ bool IsUnsandboxedSandboxType(Sandbox sa
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
       return false;
@@ -136,7 +136,7 @@ void SetCommandLineFlagsForSandboxType(b
 #endif
     case Sandbox::kPrintCompositor:
     case Sandbox::kAudio:
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     case Sandbox::kVideoCapture:
 #endif
 #if BUILDFLAG(IS_WIN)
@@ -147,10 +147,10 @@ void SetCommandLineFlagsForSandboxType(b
     case Sandbox::kMediaFoundationCdm:
     case Sandbox::kWindowsSystemProxyResolver:
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
     case Sandbox::kHardwareVideoDecoding:
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kHardwareVideoEncoding:
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 #if BUILDFLAG(IS_CHROMEOS_ASH)
@@ -168,10 +168,10 @@ void SetCommandLineFlagsForSandboxType(b
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
@@ -181,7 +181,7 @@ void SetCommandLineFlagsForSandboxType(b
           switches::kServiceSandboxType,
           StringFromUtilitySandboxType(sandbox_type));
       break;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kZygoteIntermediateSandbox:
       break;
 #endif
@@ -221,7 +221,7 @@ sandbox::mojom::Sandbox SandboxTypeFromC
     return Sandbox::kUtility;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Intermediate process gains a sandbox later.
   if (process_type == switches::kZygoteProcessType)
     return Sandbox::kZygoteIntermediateSandbox;
@@ -267,7 +267,7 @@ std::string StringFromUtilitySandboxType
       return switches::kUtilitySandbox;
     case Sandbox::kAudio:
       return switches::kAudioSandbox;
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     case Sandbox::kVideoCapture:
       return switches::kVideoCaptureSandbox;
 #endif
@@ -281,11 +281,11 @@ std::string StringFromUtilitySandboxType
     case Sandbox::kScreenAI:
       return switches::kScreenAISandbox;
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case Sandbox::kVideoEffects:
       return switches::kVideoEffectsSandbox;
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     case Sandbox::kOnDeviceTranslation:
       return switches::kOnDeviceTranslationSandbox;
 #endif
@@ -305,11 +305,11 @@ std::string StringFromUtilitySandboxType
     case Sandbox::kMirroring:
       return switches::kMirroringSandbox;
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
     case Sandbox::kHardwareVideoDecoding:
       return switches::kHardwareVideoDecodingSandbox;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kHardwareVideoEncoding:
       return switches::kHardwareVideoEncodingSandbox;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -328,7 +328,7 @@ std::string StringFromUtilitySandboxType
       // The following are not utility processes so should not occur.
     case Sandbox::kRenderer:
     case Sandbox::kGpu:
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kZygoteIntermediateSandbox:
 #endif
       NOTREACHED();
@@ -399,25 +399,25 @@ sandbox::mojom::Sandbox UtilitySandboxTy
   if (sandbox_string == switches::kScreenAISandbox)
     return Sandbox::kScreenAI;
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (sandbox_string == switches::kVideoEffectsSandbox) {
     return Sandbox::kVideoEffects;
   }
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (sandbox_string == switches::kOnDeviceTranslationSandbox) {
     return Sandbox::kOnDeviceTranslation;
   }
 #endif
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   if (sandbox_string == switches::kVideoCaptureSandbox)
     return Sandbox::kVideoCapture;
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
   if (sandbox_string == switches::kHardwareVideoDecodingSandbox)
     return Sandbox::kHardwareVideoDecoding;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (sandbox_string == switches::kHardwareVideoEncodingSandbox)
     return Sandbox::kHardwareVideoEncoding;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
