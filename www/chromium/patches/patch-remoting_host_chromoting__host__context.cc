$NetBSD: patch-remoting_host_chromoting__host__context.cc,v 1.14 2026/01/19 16:14:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/chromoting_host_context.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ remoting/host/chromoting_host_context.cc
@@ -335,7 +335,7 @@ std::unique_ptr<ChromotingHostContext> C
   // on a UI thread.
   scoped_refptr<AutoThreadTaskRunner> input_task_runner =
       AutoThread::CreateWithType("ChromotingInputThread", ui_task_runner,
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
                                  base::MessagePumpType::UI);
 #else
                                  base::MessagePumpType::IO);
