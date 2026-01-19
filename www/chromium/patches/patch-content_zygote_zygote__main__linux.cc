$NetBSD: patch-content_zygote_zygote__main__linux.cc,v 1.14 2026/01/19 16:14:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/zygote/zygote_main_linux.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ content/zygote/zygote_main_linux.cc
@@ -11,7 +11,9 @@
 #include <stddef.h>
 #include <stdint.h>
 #include <string.h>
+#if !BUILDFLAG(IS_BSD)
 #include <sys/prctl.h>
+#endif
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -41,7 +43,9 @@
 #include "sandbox/linux/services/thread_helpers.h"
 #include "sandbox/linux/suid/client/setuid_sandbox_client.h"
 #include "sandbox/policy/linux/sandbox_debug_handling_linux.h"
+#if !BUILDFLAG(IS_BSD)
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 #include "sandbox/policy/sandbox.h"
 #include "sandbox/policy/switches.h"
 #include "third_party/icu/source/i18n/unicode/timezone.h"
@@ -50,11 +54,13 @@ namespace content {
 
 namespace {
 
+#if !BUILDFLAG(IS_BSD)
 void CloseFds(const std::vector<int>& fds) {
   for (const auto& it : fds) {
     PCHECK(0 == IGNORE_EINTR(close(it)));
   }
 }
+#endif
 
 base::OnceClosure ClosureFromTwoClosures(base::OnceClosure one,
                                          base::OnceClosure two) {
@@ -157,9 +163,11 @@ static void EnterLayerOneSandbox(sandbox
     CHECK(!using_layer1_sandbox);
   }
 }
+#endif
 
 bool ZygoteMain(
     std::vector<std::unique_ptr<ZygoteForkDelegate>> fork_delegates) {
+#if !BUILDFLAG(IS_BSD)
   sandbox::SetAmZygoteOrRenderer(true, GetSandboxFD());
 
   auto* linux_sandbox = sandbox::policy::SandboxLinux::GetInstance();
@@ -224,6 +232,9 @@ bool ZygoteMain(
 
   // This function call can return multiple times, once per fork().
   return zygote.ProcessRequests();
+#else
+  return false;
+#endif
 }
 
 }  // namespace content
