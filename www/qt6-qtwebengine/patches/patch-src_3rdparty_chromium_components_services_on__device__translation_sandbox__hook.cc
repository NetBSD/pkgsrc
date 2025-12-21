$NetBSD: patch-src_3rdparty_chromium_components_services_on__device__translation_sandbox__hook.cc,v 1.1 2025/12/21 09:38:24 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/services/on_device_translation/sandbox_hook.cc.orig	2025-11-14 07:55:10.000000000 +0000
+++ src/3rdparty/chromium/components/services/on_device_translation/sandbox_hook.cc
@@ -7,12 +7,15 @@
 #include "components/services/on_device_translation/translate_kit_client.h"
 #include "sandbox/linux/syscall_broker/broker_command.h"
 
+#if !BUILDFLAG(IS_BSD)
 using sandbox::syscall_broker::BrokerFilePermission;
 using sandbox::syscall_broker::MakeBrokerCommandSet;
+#endif
 
 namespace on_device_translation {
 namespace {
 
+#if !BUILDFLAG(IS_BSD)
 // Gets the file permissions required by the TranslateKit
 std::vector<BrokerFilePermission> GetOnDeviceTranslationFilePermissions() {
   std::vector<BrokerFilePermission> permissions{
@@ -21,6 +24,7 @@ std::vector<BrokerFilePermission> GetOnD
   };
   return permissions;
 }
+#endif
 
 }  // namespace
 
@@ -29,6 +33,7 @@ bool OnDeviceTranslationSandboxHook(
   // Call `TranslateKitClient::Get()` to load libtranslatekit.so
   TranslateKitClient::Get();
 
+#if !BUILDFLAG(IS_BSD)
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
   instance->StartBrokerProcess(MakeBrokerCommandSet({
                                    sandbox::syscall_broker::COMMAND_OPEN,
@@ -36,6 +41,7 @@ bool OnDeviceTranslationSandboxHook(
                                GetOnDeviceTranslationFilePermissions(),
                                options);
   instance->EngageNamespaceSandboxIfPossible();
+#endif
 
   return true;
 }
