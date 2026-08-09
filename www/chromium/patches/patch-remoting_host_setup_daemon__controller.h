$NetBSD: patch-remoting_host_setup_daemon__controller.h,v 1.4 2026/08/09 06:31:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/setup/daemon_controller.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ remoting/host/setup/daemon_controller.h
@@ -152,13 +152,13 @@ class DaemonController : public base::Re
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
@@ -227,7 +227,7 @@ class DaemonController : public base::Re
   // unprivileged.
   bool is_privileged() const;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns true if the host has a multi-process architecture.
   bool is_multi_process() const;
 #endif
