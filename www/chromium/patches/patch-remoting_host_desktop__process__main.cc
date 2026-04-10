$NetBSD: patch-remoting_host_desktop__process__main.cc,v 1.1 2026/04/10 17:31:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/desktop_process_main.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ remoting/host/desktop_process_main.cc
@@ -28,7 +28,7 @@
 #include "remoting/host/desktop_process.h"
 #include "remoting/host/me2me_desktop_environment.h"
 
-#if BUILDFLAG(IS_LINUX) && defined(REMOTING_USE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_X11)
 #include <gtk/gtk.h>
 
 #include "ui/gfx/x/xlib_support.h"
@@ -52,7 +52,7 @@ int DesktopProcessMain() {
   const base::CommandLine* command_line =
       base::CommandLine::ForCurrentProcess();
 
-#if BUILDFLAG(IS_LINUX) && defined(REMOTING_USE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_X11)
   // Initialize Xlib for multi-threaded use, allowing non-Chromium code to
   // use X11 safely (such as the WebRTC capturer, GTK ...)
   x11::InitXlib();
