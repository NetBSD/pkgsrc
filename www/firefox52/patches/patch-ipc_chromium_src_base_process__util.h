$NetBSD: patch-ipc_chromium_src_base_process__util.h,v 1.1.28.1 2020/10/04 18:31:37 bsiegert Exp $

--- ipc/chromium/src/base/process_util.h.orig	2017-04-11 04:13:12.000000000 +0200
+++ ipc/chromium/src/base/process_util.h	2020-09-29 15:22:02.249538989 +0200
@@ -43,6 +43,9 @@
 typedef PROCESSENTRY32 ProcessEntry;
 typedef IO_COUNTERS IoCounters;
 #elif defined(OS_POSIX)
+#ifndef NAME_MAX
+#define NAME_MAX _POSIX_NAME_MAX
+#endif
 // TODO(port): we should not rely on a Win32 structure.
 struct ProcessEntry {
   int pid;
@@ -75,7 +78,8 @@ enum ProcessArchitecture {
   PROCESS_ARCH_PPC = 0x4,
   PROCESS_ARCH_ARM = 0x8,
   PROCESS_ARCH_MIPS = 0x10,
-  PROCESS_ARCH_ARM64 = 0x20
+  PROCESS_ARCH_ARM64 = 0x20,
+  PROCESS_ARCH_SPARC = 0x40
 };
 
 inline ProcessArchitecture GetCurrentProcessArchitecture()
@@ -93,6 +97,8 @@ inline ProcessArchitecture GetCurrentPro
   currentArchitecture = base::PROCESS_ARCH_MIPS;
 #elif defined(ARCH_CPU_ARM64)
   currentArchitecture = base::PROCESS_ARCH_ARM64;
+#elif defined(ARCH_CPU_SPARC)
+  currentArchitecture = base::PROCESS_ARCH_SPARC;
 #endif
   return currentArchitecture;
 }
