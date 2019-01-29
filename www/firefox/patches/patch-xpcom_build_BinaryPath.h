$NetBSD: patch-xpcom_build_BinaryPath.h,v 1.7 2019/01/29 16:28:22 ryoon Exp $

* Fix build under netbsd-7, PR pkg/52956

--- xpcom/build/BinaryPath.h.orig	2019-01-18 00:21:31.000000000 +0000
+++ xpcom/build/BinaryPath.h
@@ -21,7 +21,8 @@
     defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #include <sys/sysctl.h>
 #endif
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || \
+    (defined(__NetBSD__) && !defined(KERN_PROC_PATHNAME))
 #include <sys/stat.h>
 #endif
 #include "mozilla/UniquePtr.h"
@@ -164,7 +165,8 @@ class BinaryPath {
   }
 
 #elif defined(__FreeBSD__) || defined(__DragonFly__) || \
-    defined(__FreeBSD_kernel__) || defined(__NetBSD__)
+      defined(__FreeBSD_kernel__) || \
+      (defined(__NetBSD__) && defined(KERN_PROC_PATHNAME))
   static nsresult Get(char aResult[MAXPATHLEN]) {
     int mib[4];
     mib[0] = CTL_KERN;
@@ -246,6 +248,13 @@ class BinaryPath {
     return NS_ERROR_FAILURE;
   }
 
+#elif (defined(__NetBSD__) && !defined(KERN_PROC_PATHNAME))
+  static nsresult Get(char aResult[MAXPATHLEN])
+  {
+    char path[] = "@PREFIX@/lib/firefox/firefox";
+    sprintf(aResult, "%s", path);
+    return NS_OK;
+  }
 #else
 #error Oops, you need platform-specific code here
 #endif
