$NetBSD: patch-src_3rdparty_chromium_services_screen__ai_sandbox_screen__ai__sandbox__hook__linux.cc,v 1.1 2025/12/21 09:38:38 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.cc.orig	2025-09-25 11:10:42.000000000 +0000
+++ src/3rdparty/chromium/services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.cc
@@ -53,6 +53,7 @@ bool ScreenAIPreSandboxHook(base::FilePa
     }
   }
 
+#if !BUILDFLAG(IS_BSD)
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
 
   std::vector<BrokerFilePermission> permissions{
@@ -75,6 +76,7 @@ bool ScreenAIPreSandboxHook(base::FilePa
                             sandbox::syscall_broker::COMMAND_OPEN}),
       permissions, options);
   instance->EngageNamespaceSandboxIfPossible();
+#endif
 
   return true;
 }
