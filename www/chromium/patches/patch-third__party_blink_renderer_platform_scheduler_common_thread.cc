$NetBSD: patch-third__party_blink_renderer_platform_scheduler_common_thread.cc,v 1.14 2026/01/19 16:14:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/scheduler/common/thread.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/blink/renderer/platform/scheduler/common/thread.cc
@@ -95,7 +95,7 @@ void Thread::CreateAndSetCompositorThrea
           // the program's lifetime once assigned.
           base::Unretained(compositor_thread.get())));
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_OPENBSD)
   compositor_thread->GetTaskRunner()->PostTaskAndReplyWithResult(
       FROM_HERE, base::BindOnce(&base::PlatformThread::CurrentId),
       base::BindOnce([](base::PlatformThreadId compositor_thread_id) {
