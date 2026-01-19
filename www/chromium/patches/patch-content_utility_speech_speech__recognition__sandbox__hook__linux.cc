$NetBSD: patch-content_utility_speech_speech__recognition__sandbox__hook__linux.cc,v 1.14 2026/01/19 16:14:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/utility/speech/speech_recognition_sandbox_hook_linux.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ content/utility/speech/speech_recognition_sandbox_hook_linux.cc
@@ -12,11 +12,14 @@
 #include "sandbox/linux/syscall_broker/broker_command.h"
 #include "sandbox/linux/syscall_broker/broker_file_permission.h"
 
+#if !BUILDFLAG(IS_BSD)
 using sandbox::syscall_broker::BrokerFilePermission;
 using sandbox::syscall_broker::MakeBrokerCommandSet;
+#endif
 
 namespace speech {
 
+#if !BUILDFLAG(IS_BSD)
 namespace {
 
 // Gets the file permissions required by the Speech On-Device API (SODA).
@@ -50,9 +53,11 @@ std::vector<BrokerFilePermission> GetSod
 }
 
 }  // namespace
+#endif
 
 bool SpeechRecognitionPreSandboxHook(
     sandbox::policy::SandboxLinux::Options options) {
+#if !BUILDFLAG(IS_BSD)
 #if BUILDFLAG(ENABLE_SODA_INTEGRATION_TESTS)
   base::FilePath test_binary_path = GetSodaTestBinaryPath();
   DVLOG(0) << "SODA test binary path: " << test_binary_path.value().c_str();
@@ -75,6 +80,7 @@ bool SpeechRecognitionPreSandboxHook(
                                }),
                                GetSodaFilePermissions(), options);
   instance->EngageNamespaceSandboxIfPossible();
+#endif
 
   return true;
 }
