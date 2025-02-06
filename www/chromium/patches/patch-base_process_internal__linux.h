$NetBSD: patch-base_process_internal__linux.h,v 1.1 2025/02/06 09:57:41 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/process/internal_linux.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ base/process/internal_linux.h
@@ -140,6 +140,9 @@ TimeDelta ClockTicksToTimeDelta(int64_t 
 // arguments to the lambda.
 template <typename Lambda>
 void ForEachProcessTask(base::ProcessHandle process, Lambda&& lambda) {
+#if BUILDFLAG(IS_BSD)
+  return;
+#else
   // Iterate through the different threads tracked in /proc/<pid>/task.
   FilePath fd_path = GetProcPidDir(process).Append("task");
 
@@ -159,6 +162,7 @@ void ForEachProcessTask(base::ProcessHan
     FilePath task_path = fd_path.Append(tid_str);
     lambda(tid, task_path);
   }
+#endif
 }
 
 }  // namespace internal
