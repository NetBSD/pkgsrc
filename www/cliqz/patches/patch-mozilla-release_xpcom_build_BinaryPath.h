$NetBSD: patch-mozilla-release_xpcom_build_BinaryPath.h,v 1.1 2019/04/19 14:02:03 fox Exp $

* Fix build under netbsd-7, PR pkg/52956

Original patch from ryoon, imported from www/firefox

* Renamed firefox to cliqz to match the binary name

--- mozilla-release/xpcom/build/BinaryPath.h.orig	2019-04-03 08:46:52.000000000 +0000
+++ mozilla-release/xpcom/build/BinaryPath.h
@@ -21,7 +21,8 @@
     defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #  include <sys/sysctl.h>
 #endif
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || \
+    (defined(__NetBSD__) && !defined(KERN_PROC_PATHNAME))
 #  include <sys/stat.h>
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
+    char path[] = "@PREFIX@/lib/cliqz/cliqz";
+    sprintf(aResult, "%s", path);
+    return NS_OK;
+  }
 #else
 #  error Oops, you need platform-specific code here
 #endif
