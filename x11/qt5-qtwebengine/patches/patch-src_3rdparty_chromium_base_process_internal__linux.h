$NetBSD: patch-src_3rdparty_chromium_base_process_internal__linux.h,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/process/internal_linux.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/process/internal_linux.h
@@ -10,6 +10,7 @@
 
 #include <stddef.h>
 #include <stdint.h>
+#include <string.h>
 #include <unistd.h>
 
 #include "base/files/dir_reader_posix.h"
@@ -59,6 +60,14 @@ bool ParseProcStats(const std::string& s
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
@@ -71,6 +80,7 @@ enum ProcStatsFields {
   VM_STARTTIME = 21,   // The time the process started in clock ticks.
   VM_VSIZE = 22,       // Virtual memory size in bytes.
   VM_RSS = 23,         // Resident Set Size in pages.
+#endif
 };
 
 // Reads the |field_num|th field from |proc_stats|. Returns 0 on failure.
