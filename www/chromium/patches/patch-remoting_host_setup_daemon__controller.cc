$NetBSD: patch-remoting_host_setup_daemon__controller.cc,v 1.13 2026/11/19 19:46:05 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/setup/daemon_controller.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ remoting/host/setup/daemon_controller.cc
@@ -53,7 +53,7 @@ bool DaemonController::is_privileged() c
   return delegate_->is_privileged();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool DaemonController::is_multi_process() const {
   return delegate_->is_multi_process();
 }
