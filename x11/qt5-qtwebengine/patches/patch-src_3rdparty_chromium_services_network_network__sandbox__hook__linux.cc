$NetBSD: patch-src_3rdparty_chromium_services_network_network__sandbox__hook__linux.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/services/network/network_sandbox_hook_linux.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/services/network/network_sandbox_hook_linux.cc
@@ -14,6 +14,7 @@ using sandbox::syscall_broker::MakeBroke
 namespace network {
 
 bool NetworkPreSandboxHook(sandbox::policy::SandboxLinux::Options options) {
+#if !defined(OS_BSD)
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
 
   // TODO(tsepez): remove universal permission under filesytem root.
@@ -32,6 +33,7 @@ bool NetworkPreSandboxHook(sandbox::poli
       sandbox::policy::SandboxLinux::PreSandboxHook(), options);
 
   instance->EngageNamespaceSandboxIfPossible();
+#endif
   return true;
 }
 
