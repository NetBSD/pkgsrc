$NetBSD: patch-services_audio_audio__sandbox__hook__linux.cc,v 1.7 2025/09/12 16:02:33 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/audio/audio_sandbox_hook_linux.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ services/audio/audio_sandbox_hook_linux.cc
@@ -147,6 +147,7 @@ void AddPulseAudioFilePermissions(
 }
 #endif
 
+#if !BUILDFLAG(IS_BSD)
 std::vector<BrokerFilePermission> GetAudioFilePermissions() {
   std::vector<BrokerFilePermission> permissions{
       BrokerFilePermission::ReadOnly("/dev/urandom"),
@@ -175,10 +176,12 @@ void LoadAudioLibraries() {
     }
   }
 }
+#endif
 
 }  // namespace
 
 bool AudioPreSandboxHook(sandbox::policy::SandboxLinux::Options options) {
+#if !BUILDFLAG(IS_BSD)
   LoadAudioLibraries();
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
   instance->StartBrokerProcess(MakeBrokerCommandSet({
@@ -196,6 +199,7 @@ bool AudioPreSandboxHook(sandbox::policy
   // TODO(crbug.com/40579955) enable namespace sandbox. Currently, if
   // enabled, connect() on pulse native socket fails with ENOENT (called from
   // pa_context_connect).
+#endif
 
   return true;
 }
