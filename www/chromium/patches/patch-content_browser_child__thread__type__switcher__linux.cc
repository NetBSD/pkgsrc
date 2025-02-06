$NetBSD: patch-content_browser_child__thread__type__switcher__linux.cc,v 1.1 2025/02/06 09:58:05 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/child_thread_type_switcher_linux.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ content/browser/child_thread_type_switcher_linux.cc
@@ -20,6 +20,9 @@ void SetThreadTypeOnLauncherThread(base:
                                    base::ThreadType thread_type) {
   DCHECK(CurrentlyOnProcessLauncherTaskRunner());
 
+#if BUILDFLAG(IS_BSD)
+  NOTIMPLEMENTED();
+#else
   bool ns_pid_supported = false;
   pid_t peer_tid = base::FindThreadID(peer_pid, ns_tid, &ns_pid_supported);
   if (peer_tid == -1) {
@@ -39,6 +42,7 @@ void SetThreadTypeOnLauncherThread(base:
 
   base::PlatformThread::SetThreadType(peer_pid, peer_tid, thread_type,
                                       base::IsViaIPC(true));
+#endif
 }
 
 }  // namespace
