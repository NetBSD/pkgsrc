$NetBSD: patch-base_debug_debugger__posix.cc,v 1.14 2026/01/19 16:14:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/debug/debugger_posix.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ base/debug/debugger_posix.cc
@@ -39,6 +39,10 @@
 #include <sys/sysctl.h>
 #endif
 
+#if BUILDFLAG(IS_OPENBSD)
+#include <sys/proc.h>
+#endif
+
 #if BUILDFLAG(IS_FREEBSD)
 #include <sys/user.h>
 #endif
@@ -84,6 +88,7 @@ bool BeingDebugged() {
 
   // Initialize mib, which tells sysctl what info we want.  In this case,
   // we're looking for information about a specific process ID.
+#if !BUILDFLAG(IS_NETBSD)
   int mib[] = {CTL_KERN,
                KERN_PROC,
                KERN_PROC_PID,
@@ -94,37 +99,75 @@ bool BeingDebugged() {
                0
 #endif
   };
+#else
+  int mib[] = {CTL_KERN,
+               KERN_PROC2,
+               KERN_PROC_PID,
+               getpid(),
+               sizeof(struct kinfo_proc2),
+               1
+  };
+#endif
 
   // Caution: struct kinfo_proc is marked __APPLE_API_UNSTABLE.  The source and
   // binary interfaces may change.
+#if BUILDFLAG(IS_OPENBSD)
+  struct kinfo_proc *info;
+  size_t info_size;
+#elif BUILDFLAG(IS_NETBSD)
+  struct kinfo_proc2 info;
+  size_t info_size = sizeof(info);
+#else
   struct kinfo_proc info;
   size_t info_size = sizeof(info);
+#endif
 
 #if BUILDFLAG(IS_OPENBSD)
   if (sysctl(mib, std::size(mib), NULL, &info_size, NULL, 0) < 0) {
     return -1;
   }
 
-  mib[5] = (info_size / sizeof(struct kinfo_proc));
+  mib[5] = static_cast<int>((info_size / sizeof(struct kinfo_proc)));
+  if ((info = reinterpret_cast<kinfo_proc*>(malloc(info_size))) == NULL) {
+    is_set = true;
+    being_debugged = false;
+    return being_debugged;
+  }
+
+  int sysctl_result = sysctl(mib, std::size(mib), info, &info_size, NULL, 0);
+#elif BUILDFLAG(IS_NETBSD)
+  if (sysctl(mib, std::size(mib), NULL, &info_size, NULL, 0) < 0)
+    return -1;
+
+  mib[5] = (info_size / sizeof(struct kinfo_proc2));
 #endif
 
+#if !BUILDFLAG(IS_OPENBSD)
   int sysctl_result = sysctl(mib, std::size(mib), &info, &info_size, NULL, 0);
+#endif
   DCHECK_EQ(sysctl_result, 0);
   if (sysctl_result != 0) {
     is_set = true;
     being_debugged = false;
-    return being_debugged;
+    goto out;
   }
 
   // This process is being debugged if the P_TRACED flag is set.
   is_set = true;
 #if BUILDFLAG(IS_FREEBSD)
   being_debugged = (info.ki_flag & P_TRACED) != 0;
-#elif BUILDFLAG(IS_BSD)
+#elif BUILDFLAG(IS_OPENBSD)
+  being_debugged = (info->p_psflags & PS_TRACED) != 0;
+#elif BUILDFLAG(IS_NETBSD)
   being_debugged = (info.p_flag & P_TRACED) != 0;
 #else
   being_debugged = (info.kp_proc.p_flag & P_TRACED) != 0;
 #endif
+
+out:
+#if BUILDFLAG(IS_OPENBSD)
+  free(info);
+#endif
   return being_debugged;
 }
 
