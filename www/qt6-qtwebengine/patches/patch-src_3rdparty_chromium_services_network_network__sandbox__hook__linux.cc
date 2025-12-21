$NetBSD: patch-src_3rdparty_chromium_services_network_network__sandbox__hook__linux.cc,v 1.1 2025/12/21 09:38:37 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/services/network/network_sandbox_hook_linux.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/services/network/network_sandbox_hook_linux.cc
@@ -15,11 +15,14 @@
 #include "sandbox/linux/syscall_broker/broker_file_permission.h"
 #include "sandbox/policy/features.h"
 
+#if !BUILDFLAG(IS_BSD)
 using sandbox::syscall_broker::BrokerFilePermission;
 using sandbox::syscall_broker::MakeBrokerCommandSet;
+#endif
 
 namespace network {
 
+#if !BUILDFLAG(IS_BSD)
 sandbox::syscall_broker::BrokerCommandSet GetNetworkBrokerCommandSet() {
   return MakeBrokerCommandSet({
       sandbox::syscall_broker::COMMAND_ACCESS,
@@ -103,9 +106,11 @@ void LoadNetworkLibraries() {
   }
 }
 #endif  // BUILDFLAG(IS_CHROMEOS)
+#endif
 
 bool NetworkPreSandboxHook(std::vector<std::string> network_context_parent_dirs,
                            sandbox::policy::SandboxLinux::Options options) {
+#if !BUILDFLAG(IS_BSD)
 #if BUILDFLAG(IS_CHROMEOS)
   LoadNetworkLibraries();
 #endif
@@ -118,6 +123,7 @@ bool NetworkPreSandboxHook(std::vector<s
       GetNetworkBrokerCommandSet(),
       GetNetworkFilePermissions(std::move(network_context_parent_dirs)),
       options);
+#endif
 
   return true;
 }
