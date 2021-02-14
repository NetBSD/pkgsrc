$NetBSD: patch-src_nxt__cert.c,v 1.1 2021/02/14 11:56:57 otis Exp $

Use more portable way to find regular files.

--- src/nxt_cert.c.orig	2020-10-08 16:04:40.000000000 +0000
+++ src/nxt_cert.c
@@ -9,6 +9,9 @@
 #include <nxt_cert.h>
 
 #include <dirent.h>
+#include <fcntl.h>
+#include <sys/types.h>
+#include <sys/stat.h>
 
 #include <openssl/bio.h>
 #include <openssl/pem.h>
@@ -809,6 +812,7 @@ nxt_cert_store_load(nxt_task_t *task, nx
     nxt_runtime_t    *rt;
     struct dirent    *de;
     nxt_cert_item_t  *item;
+    struct stat      cert_statbuf;
 
     rt = task->thread->runtime;
 
@@ -838,7 +842,8 @@ nxt_cert_store_load(nxt_task_t *task, nx
             break;
         }
 
-        if (de->d_type != DT_REG) {
+        if (stat(de->d_name, &cert_statbuf) == -1 ||
+            (cert_statbuf.st_mode & S_IFREG) == 0) {
             continue;
         }
 
