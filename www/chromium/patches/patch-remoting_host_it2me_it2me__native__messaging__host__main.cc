$NetBSD: patch-remoting_host_it2me_it2me__native__messaging__host__main.cc,v 1.2 2025/05/16 16:08:29 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/it2me/it2me_native_messaging_host_main.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ remoting/host/it2me/it2me_native_messaging_host_main.cc
@@ -30,7 +30,7 @@
 #include "remoting/host/resources.h"
 #include "remoting/host/usage_stats_consent.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #if defined(REMOTING_USE_X11)
 #include <gtk/gtk.h>
 #include "base/linux_util.h"
@@ -75,7 +75,7 @@ bool CurrentProcessHasUiAccess() {
 // Creates a It2MeNativeMessagingHost instance, attaches it to stdin/stdout and
 // runs the task executor until It2MeNativeMessagingHost signals shutdown.
 int It2MeNativeMessagingHostMain(int argc, char** argv) {
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(REMOTING_USE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_X11)
   // Initialize Xlib for multi-threaded use, allowing non-Chromium code to
   // use X11 safely (such as the WebRTC capturer, GTK ...)
   x11::InitXlib();
@@ -121,7 +121,7 @@ int It2MeNativeMessagingHostMain(int arg
 
   remoting::LoadResources("");
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(REMOTING_USE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_X11)
   // Required for any calls into GTK functions, such as the Disconnect and
   // Continue windows. Calling with nullptr arguments because we don't have
   // any command line arguments for gtk to consume.
@@ -249,7 +249,7 @@ int It2MeNativeMessagingHostMain(int arg
       PolicyWatcher::CreateWithTaskRunner(context->file_task_runner(),
                                           context->management_service());
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(REMOTING_USE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_X11)
   scoped_refptr<AutoThreadTaskRunner> input_task_runner;
   // Create an X11EventSource on all UI threads, so the global X11 connection
   // (x11::Connection::Get()) can dispatch X events.
@@ -273,7 +273,7 @@ int It2MeNativeMessagingHostMain(int arg
   // Run the loop until channel is alive.
   run_loop.Run();
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(REMOTING_USE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_X11)
   input_task_runner->PostTask(FROM_HERE, base::BindOnce([]() {
                                 delete ui::X11EventSource::GetInstance();
                               }));
