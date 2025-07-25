$NetBSD: patch-services_screen__ai_sandbox_screen__ai__sandbox__hook__linux.cc,v 1.4 2025/07/25 16:17:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.cc
@@ -58,6 +58,7 @@ bool ScreenAIPreSandboxHook(base::FilePa
     }
   }
 
+#if !BUILDFLAG(IS_BSD)
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
 
   std::vector<BrokerFilePermission> permissions{
@@ -79,6 +80,7 @@ bool ScreenAIPreSandboxHook(base::FilePa
                             sandbox::syscall_broker::COMMAND_OPEN}),
       permissions, options);
   instance->EngageNamespaceSandboxIfPossible();
+#endif
 
   return true;
 }
