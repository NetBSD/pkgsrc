$NetBSD: patch-support_htdbm.c,v 1.1 2013/06/20 09:06:45 taca Exp $

Fix for htpasswd: https://issues.apache.org/bugzilla/show_bug.cgi?id=54735

--- support/htdbm.c.orig	2012-12-12 19:31:29.000000000 +0000
+++ support/htdbm.c
@@ -110,6 +110,7 @@ static apr_status_t htdbm_init(apr_pool_
 #endif
 
     apr_pool_create( pool, NULL);
+    apr_pool_abort_set(abort_on_oom, *pool);
     apr_file_open_stderr(&errfile, *pool);
     apr_signal(SIGINT, (void (*)(int)) htdbm_interrupted);
 
