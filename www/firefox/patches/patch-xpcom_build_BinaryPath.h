$NetBSD: patch-xpcom_build_BinaryPath.h,v 1.5 2018/11/04 00:38:45 ryoon Exp $

--- xpcom/build/BinaryPath.h.orig	2018-10-18 20:06:16.000000000 +0000
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
@@ -257,6 +259,13 @@ private:
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
