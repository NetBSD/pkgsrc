$NetBSD: patch-remoting_host_setup_daemon__controller.cc,v 1.5 2026/09/02 13:13:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/setup/daemon_controller.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ remoting/host/setup/daemon_controller.cc
@@ -63,7 +63,7 @@ bool DaemonController::is_privileged() c
   return delegate_->is_privileged();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool DaemonController::is_multi_process() const {
   return delegate_->is_multi_process();
 }
