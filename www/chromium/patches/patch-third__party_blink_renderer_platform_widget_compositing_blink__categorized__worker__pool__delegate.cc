$NetBSD: patch-third__party_blink_renderer_platform_widget_compositing_blink__categorized__worker__pool__delegate.cc,v 1.17 2026/04/10 17:31:59 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/widget/compositing/blink_categorized_worker_pool_delegate.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ third_party/blink/renderer/platform/widget/compositing/blink_categorized_worker_pool_delegate.cc
@@ -27,7 +27,7 @@ BlinkCategorizedWorkerPoolDelegate& Blin
 
 void BlinkCategorizedWorkerPoolDelegate::NotifyThreadWillRun(
     base::PlatformThreadId tid) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   scoped_refptr<base::TaskRunner> task_runner =
       Thread::MainThread()->GetTaskRunner(MainThreadTaskRunnerRestricted());
   task_runner->PostTask(FROM_HERE, base::BindOnce(
