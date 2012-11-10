$NetBSD: patch-lib_Xm_Xmos.c,v 1.1 2012/11/10 17:10:11 ryoon Exp $

--- lib/Xm/Xmos.c.orig	2012-10-22 14:50:35.000000000 +0000
+++ lib/Xm/Xmos.c
@@ -82,6 +82,17 @@ extern int regex();
 
 #include <sys/stat.h>
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#  if __NetBSD_Version__ >= 299001000 /* NetBSD 2.99.10 has getpw*_r*/
+#    if !defined(_POSIX_THREAD_SAFE_FUNCTIONS)
+#      define _POSIX_THREAD_SAFE_FUNCTIONS 200112L
+#    endif
+#  else
+#    define XNO_MTSAFE_PWDAPI
+#  endif
+#endif
+
 #define X_INCLUDE_PWD_H
 #define X_INCLUDE_DIRENT_H
 #define XOS_USE_XT_LOCKING
