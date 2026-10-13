$NetBSD: patch-content_browser_sandbox__host__linux.cc,v 1.29 2026/10/13 13:16:41 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/sandbox_host_linux.cc.orig	2026-10-06 00:06:58.000000000 +0000
+++ content/browser/sandbox_host_linux.cc
@@ -45,6 +45,7 @@ void SandboxHostLinux::Init() {
   // Instead, it replies on a temporary socket provided by the caller.
   PCHECK(0 == shutdown(browser_socket, SHUT_WR)) << "shutdown";
 
+#if !BUILDFLAG(IS_BSD) 
   int pipefds[2];
   CHECK(0 == pipe(pipefds));
   const int child_lifeline_fd = pipefds[0];
@@ -55,6 +56,7 @@ void SandboxHostLinux::Init() {
   ipc_thread_ = std::make_unique<base::DelegateSimpleThread>(
       ipc_handler_.get(), "sandbox_ipc_thread");
   ipc_thread_->Start();
+#endif
 }
 
 }  // namespace content
