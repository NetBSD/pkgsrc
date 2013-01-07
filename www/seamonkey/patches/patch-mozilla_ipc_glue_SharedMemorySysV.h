$NetBSD: patch-mozilla_ipc_glue_SharedMemorySysV.h,v 1.3 2013/01/07 21:55:30 ryoon Exp $

--- mozilla/ipc/glue/SharedMemorySysV.h.orig	2012-11-18 10:19:38.000000000 +0000
+++ mozilla/ipc/glue/SharedMemorySysV.h
@@ -8,7 +8,7 @@
 #ifndef mozilla_ipc_SharedMemorySysV_h
 #define mozilla_ipc_SharedMemorySysV_h
 
-#if defined(OS_LINUX) && !defined(ANDROID)
+#if (defined(OS_LINUX) && !defined(ANDROID)) || defined(OS_BSD)
 
 // SysV shared memory isn't available on Windows, but we define the
 // following macro so that #ifdefs are clearer (compared to #ifdef
