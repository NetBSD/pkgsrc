$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_platform_scheduler_common_thread.cc,v 1.1 2025/12/21 09:38:41 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/blink/renderer/platform/scheduler/common/thread.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/scheduler/common/thread.cc
@@ -88,7 +88,7 @@ void Thread::CreateAndSetCompositorThrea
             "Compositor");
       }));
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_OPENBSD)
   compositor_thread->GetTaskRunner()->PostTaskAndReplyWithResult(
       FROM_HERE, base::BindOnce(&base::PlatformThread::CurrentId),
       base::BindOnce([](base::PlatformThreadId compositor_thread_id) {
