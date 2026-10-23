$NetBSD: patch-remoting_host_setup_daemon__controller.h,v 1.11 2026/10/23 15:05:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/setup/daemon_controller.h.orig	2026-10-19 20:07:21.000000000 +0000
+++ remoting/host/setup/daemon_controller.h
@@ -156,13 +156,13 @@ class DaemonController : public base::Re
     // unprivileged.
     virtual bool is_privileged() const = 0;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Returns true if the host has a multi-process architecture.
     virtual bool is_multi_process() const = 0;
 #endif
   };
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set the host type. If nullptr is passed (the default), the host type will
   // be automatically determined by checking which host type is running. If none
   // is running, HostType::GetDefaultHostType() will be used.
@@ -231,7 +231,7 @@ class DaemonController : public base::Re
   // unprivileged.
   bool is_privileged() const;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns true if the host has a multi-process architecture.
   bool is_multi_process() const;
 #endif
