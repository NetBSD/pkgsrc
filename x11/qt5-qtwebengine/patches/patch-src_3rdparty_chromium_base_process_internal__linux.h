$NetBSD: patch-src_3rdparty_chromium_base_process_internal__linux.h,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/process/internal_linux.h.orig	2020-06-25 09:31:18.000000000 +0000
+++ src/3rdparty/chromium/base/process/internal_linux.h
@@ -55,6 +55,14 @@ bool ParseProcStats(const std::string& s
 // If the ordering ever changes, carefully review functions that use these
 // values.
 enum ProcStatsFields {
+#if defined(OS_BSD)
+  VM_COMM = 0,         // Command name.
+  VM_PPID = 2,         // Parent process id.
+  VM_PGRP = 3,         // Process group id.
+  VM_STARTTIME = 7,    // The process start time.
+  VM_UTIME = 8,        // The user time.
+  VM_STIME = 9,        // The system time
+#else
   VM_COMM = 1,         // Filename of executable, without parentheses.
   VM_STATE = 2,        // Letter indicating the state of the process.
   VM_PPID = 3,         // PID of the parent.
@@ -67,6 +75,7 @@ enum ProcStatsFields {
   VM_STARTTIME = 21,   // The time the process started in clock ticks.
   VM_VSIZE = 22,       // Virtual memory size in bytes.
   VM_RSS = 23,         // Resident Set Size in pages.
+#endif
 };
 
 // Reads the |field_num|th field from |proc_stats|. Returns 0 on failure.
