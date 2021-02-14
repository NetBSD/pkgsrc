$NetBSD: patch-src_nxt__conf__validation.c,v 1.1 2021/02/14 11:56:57 otis Exp $

NetBSD portability,
https://mail-index.netbsd.org/tech-userlevel/2014/08/15/msg008729.html

This patch is going to be reviewed by the vendor.

--- src/nxt_conf_validation.c.orig	2020-11-20 11:59:37.258205794 -0500
+++ src/nxt_conf_validation.c	2020-11-20 12:11:43.940557782 -0500
@@ -1426,10 +1426,10 @@
 
     size = nxt_conf_get_number(value);
 
-    if (size < PTHREAD_STACK_MIN) {
+    if (size < sysconf(_SC_THREAD_STACK_MIN)) {
         return nxt_conf_vldt_error(vldt, "The \"thread_stack_size\" number "
                                    "must be equal to or greater than %d.",
-                                   PTHREAD_STACK_MIN);
+                                   sysconf(_SC_THREAD_STACK_MIN));
     }
 
     if ((size % nxt_pagesize) != 0) {
