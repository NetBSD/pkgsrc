$NetBSD: patch-xpcom_build_BinaryPath.h,v 1.3 2018/01/31 14:02:18 ryoon Exp $

* Fix build under netbsd-7, PR pkg/52956

--- xpcom/build/BinaryPath.h.orig	2018-01-11 20:17:07.000000000 +0000
+++ xpcom/build/BinaryPath.h
@@ -22,7 +22,8 @@
     defined(__OpenBSD__)
 #include <sys/sysctl.h>
 #endif
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || \
+    (defined(__NetBSD__) && !defined(KERN_PROC_PATHNAME))
 #include <sys/stat.h>
 #endif
 #include "mozilla/UniquePtr.h"
@@ -172,7 +173,8 @@ private:
   }
 
 #elif defined(__FreeBSD__) || defined(__DragonFly__) || \
-      defined(__FreeBSD_kernel__) || defined(__NetBSD__)
+      defined(__FreeBSD_kernel__) || \
+      (defined(__NetBSD__) && defined(KERN_PROC_PATHNAME))
   static nsresult Get(char aResult[MAXPATHLEN])
   {
     int mib[4];
@@ -195,7 +197,8 @@ private:
     return NS_OK;
   }
 
-#elif defined(__OpenBSD__)
+#elif defined(__OpenBSD__) || \
+      (defined(__NetBSD__) && !defined(KERN_PROC_PATHNAME))
   static nsresult Get(char aResult[MAXPATHLEN])
   {
     int mib[4];
