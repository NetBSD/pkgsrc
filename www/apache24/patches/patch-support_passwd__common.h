$NetBSD: patch-support_passwd__common.h,v 1.1 2013/06/20 09:06:45 taca Exp $

Fix for htpasswd: https://issues.apache.org/bugzilla/show_bug.cgi?id=54735

--- support/passwd_common.h.orig	2012-12-11 10:37:25.000000000 +0000
+++ support/passwd_common.h
@@ -80,10 +80,17 @@ struct passwd_ctx {
     enum {
         PW_PROMPT = 0,
         PW_ARG,
-        PW_STDIN
+        PW_STDIN,
+        PW_PROMPT_VERIFY,
     } passwd_src;
 };
 
+
+/*
+ * To be used as apr_pool_abort_fn
+ */
+int abort_on_oom(int rc);
+
 /*
  * Write a line to the file. On error, print a message and exit
  */
