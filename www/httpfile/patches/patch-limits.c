$NetBSD: patch-limits.c,v 1.1 2022/01/04 22:35:24 schmonz Exp $

Work around "unable to set RLIMIT_DATA to 0" on macOS.

--- limits.c.orig	2021-12-28 09:09:06.000000000 +0000
+++ limits.c
@@ -41,6 +41,7 @@ int limits(void) {
 /* if memory limit is greater than 64MB */
 /* set memory limit to 128MB            */
 #define DATAMAX 134217728
+#ifndef __APPLE__
 #ifdef RLIMIT_DATA
     if (getrlimit(RLIMIT_DATA, &r) == -1) {
         log_e1("unable to get RLIMIT_DATA");
@@ -55,6 +56,7 @@ int limits(void) {
         log_t2("setrlimit RLIMIT_DATA set to ", lognum(DATAMAX));
     }
 #endif
+#endif
 
     ret = 1;
 cleanup:
