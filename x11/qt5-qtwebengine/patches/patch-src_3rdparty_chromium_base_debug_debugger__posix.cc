$NetBSD: patch-src_3rdparty_chromium_base_debug_debugger__posix.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/debug/debugger_posix.cc.orig	2020-06-25 09:31:18.000000000 +0000
+++ src/3rdparty/chromium/base/debug/debugger_posix.cc
@@ -93,6 +93,7 @@ bool BeingDebugged() {
 
   // Initialize mib, which tells sysctl what info we want.  In this case,
   // we're looking for information about a specific process ID.
+#if defined(OS_FREEBSD) || defined(OS_OPENBSD)
   int mib[] = {
     CTL_KERN,
     KERN_PROC,
@@ -103,10 +104,24 @@ bool BeingDebugged() {
     0
 #endif
   };
+#elif defined(OS_NETBSD)
+  int mib[] = {
+    CTL_KERN,
+    KERN_PROC2,
+    KERN_PROC_PID,
+    getpid(),
+    sizeof(struct kinfo_proc2),
+    1
+  };
+#endif
 
   // Caution: struct kinfo_proc is marked __APPLE_API_UNSTABLE.  The source and
   // binary interfaces may change.
+#if defined(OS_NETBSD)
+  struct kinfo_proc2 info;
+#else
   struct kinfo_proc info;
+#endif
   size_t info_size = sizeof(info);
 
 #if defined(OS_OPENBSD)
@@ -114,6 +129,11 @@ bool BeingDebugged() {
     return -1;
 
   mib[5] = (info_size / sizeof(struct kinfo_proc));
+#elif defined(OS_NETBSD)
+  if (sysctl(mib, base::size(mib), NULL, &info_size, NULL, 0) < 0)
+    return -1;
+
+  mib[5] = (info_size / sizeof(struct kinfo_proc2));
 #endif
 
   int sysctl_result = sysctl(mib, base::size(mib), &info, &info_size, NULL, 0);
