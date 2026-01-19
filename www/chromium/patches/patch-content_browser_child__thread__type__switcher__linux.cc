$NetBSD: patch-content_browser_child__thread__type__switcher__linux.cc,v 1.14 2026/01/19 16:14:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/child_thread_type_switcher_linux.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ content/browser/child_thread_type_switcher_linux.cc
@@ -6,6 +6,7 @@
 
 #include "base/linux_util.h"
 #include "base/logging.h"
+#include "base/notimplemented.h"
 #include "base/process/process_handle.h"
 #include "base/task/single_thread_task_runner.h"
 #include "base/threading/platform_thread.h"
@@ -20,6 +21,9 @@ void SetThreadTypeOnLauncherThread(base:
                                    base::ThreadType thread_type) {
   DCHECK(CurrentlyOnProcessLauncherTaskRunner());
 
+#if BUILDFLAG(IS_BSD)
+  NOTIMPLEMENTED();
+#else
   bool ns_pid_supported = false;
   pid_t peer_tid =
       base::FindThreadID(peer_pid, ns_tid.raw(), &ns_pid_supported);
@@ -42,6 +46,7 @@ void SetThreadTypeOnLauncherThread(base:
   base::PlatformThread::SetThreadType(peer_pid,
                                       base::PlatformThreadId(peer_tid),
                                       thread_type, base::IsViaIPC(true));
+#endif
 }
 
 }  // namespace
@@ -70,7 +75,7 @@ void ChildThreadTypeSwitcher::SetPid(bas
   }
 }
 
-void ChildThreadTypeSwitcher::SetThreadType(int32_t ns_tid,
+void ChildThreadTypeSwitcher::SetThreadType(uint64_t ns_tid,
                                             base::ThreadType thread_type) {
   // This function is only used on platforms with 32-bit thread ids.
   static_assert(sizeof(ns_tid) == sizeof(base::PlatformThreadId));
