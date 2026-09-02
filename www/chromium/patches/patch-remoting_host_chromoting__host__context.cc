$NetBSD: patch-remoting_host_chromoting__host__context.cc,v 1.25 2026/09/02 13:13:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/chromoting_host_context.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ remoting/host/chromoting_host_context.cc
@@ -321,7 +321,7 @@ std::unique_ptr<ChromotingHostContext> C
   // on a UI thread.
   scoped_refptr<AutoThreadTaskRunner> input_task_runner =
       AutoThread::CreateWithType("ChromotingInputThread", ui_task_runner,
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
                                  base::MessagePumpType::UI);
 #else
                                  base::MessagePumpType::IO);
