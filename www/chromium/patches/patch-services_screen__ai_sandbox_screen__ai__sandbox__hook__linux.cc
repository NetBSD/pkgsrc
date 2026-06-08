$NetBSD: patch-services_screen__ai_sandbox_screen__ai__sandbox__hook__linux.cc,v 1.21 2026/06/08 13:12:45 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.cc.orig	2026-05-28 23:24:11.000000000 +0000
+++ services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.cc
@@ -71,6 +71,7 @@ bool ScreenAIPreSandboxHook(base::FilePa
     }
   }
 
+#if !BUILDFLAG(IS_BSD)
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
 
   std::vector<BrokerFilePermission> permissions{
@@ -92,6 +93,7 @@ bool ScreenAIPreSandboxHook(base::FilePa
                             sandbox::syscall_broker::COMMAND_OPEN}),
       permissions, options);
   instance->EngageNamespaceSandboxIfPossible();
+#endif
 
   return true;
 }
