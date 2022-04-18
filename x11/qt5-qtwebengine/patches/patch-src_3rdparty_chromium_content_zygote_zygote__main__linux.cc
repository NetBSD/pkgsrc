$NetBSD: patch-src_3rdparty_chromium_content_zygote_zygote__main__linux.cc,v 1.1 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/content/zygote/zygote_main_linux.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/content/zygote/zygote_main_linux.cc
@@ -11,7 +11,9 @@
 #include <stddef.h>
 #include <stdint.h>
 #include <string.h>
+#if !defined(OS_BSD)
 #include <sys/prctl.h>
+#endif
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -49,6 +51,7 @@ namespace content {
 
 namespace {
 
+#if !defined(OS_BSD)
 void CloseFds(const std::vector<int>& fds) {
   for (const auto& it : fds) {
     PCHECK(0 == IGNORE_EINTR(close(it)));
@@ -66,9 +69,11 @@ base::OnceClosure ClosureFromTwoClosures
       },
       std::move(one), std::move(two));
 }
+#endif
 
 }  // namespace
 
+#if !defined(OS_BSD)
 // This function triggers the static and lazy construction of objects that need
 // to be created before imposing the sandbox.
 static void ZygotePreSandboxInit() {
@@ -175,9 +180,11 @@ static void EnterLayerOneSandbox(sandbox
     CHECK(!using_layer1_sandbox);
   }
 }
+#endif
 
 bool ZygoteMain(
     std::vector<std::unique_ptr<ZygoteForkDelegate>> fork_delegates) {
+#if !defined(OS_BSD)
   sandbox::SetAmZygoteOrRenderer(true, GetSandboxFD());
 
   auto* linux_sandbox = sandbox::policy::SandboxLinux::GetInstance();
@@ -243,6 +250,9 @@ bool ZygoteMain(
 
   // This function call can return multiple times, once per fork().
   return zygote.ProcessRequests();
+#else
+  return false;
+#endif
 }
 
 }  // namespace content
