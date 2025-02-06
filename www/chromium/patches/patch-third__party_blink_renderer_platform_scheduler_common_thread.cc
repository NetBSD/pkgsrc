$NetBSD: patch-third__party_blink_renderer_platform_scheduler_common_thread.cc,v 1.1 2025/02/06 09:58:24 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/scheduler/common/thread.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/blink/renderer/platform/scheduler/common/thread.cc
@@ -87,7 +87,7 @@ void Thread::CreateAndSetCompositorThrea
             "Compositor");
       }));
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_OPENBSD)
   compositor_thread->GetTaskRunner()->PostTaskAndReplyWithResult(
       FROM_HERE, base::BindOnce(&base::PlatformThread::CurrentId),
       base::BindOnce([](base::PlatformThreadId compositor_thread_id) {
