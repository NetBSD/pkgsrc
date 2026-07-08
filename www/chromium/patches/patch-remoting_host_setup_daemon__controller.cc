$NetBSD: patch-remoting_host_setup_daemon__controller.cc,v 1.3 2026/07/08 13:42:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/setup/daemon_controller.cc.orig	2026-07-06 22:58:46.000000000 +0000
+++ remoting/host/setup/daemon_controller.cc
@@ -63,7 +63,7 @@ bool DaemonController::is_privileged() c
   return delegate_->is_privileged();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool DaemonController::is_multi_process() const {
   return delegate_->is_multi_process();
 }
