$NetBSD: patch-file.c,v 1.1 2024/12/17 13:35:10 ryoon Exp $

* Revert DL/DT/DD related change. It is broken and cannot display
  doc-jp/FAQ.html and http://www.cpm.z80.de/ correctly, for example.
  The old behavior may not be perfect however it works.

--- file.c.orig	2023-01-21 02:01:52.000000000 +0000
+++ file.c
@@ -4410,14 +4410,6 @@ process_idattr(struct readbuffer *obuf, 
         envs[h_env->envc].indent = envs[h_env->envc - 1].indent; \
     }
 
-#define PUSH_ENV_NOINDENT(cmd) \
-    if (++h_env->envc_real < h_env->nenv) { \
-      ++h_env->envc; \
-      envs[h_env->envc].env = cmd; \
-      envs[h_env->envc].count = 0; \
-      envs[h_env->envc].indent = envs[h_env->envc - 1].indent; \
-    }
-
 #define POP_ENV \
     if (h_env->envc_real-- < h_env->nenv) \
       h_env->envc--;
@@ -4660,7 +4652,6 @@ HTMLtagproc1(struct parsed_tag *tag, str
     case HTML_N_OL:
     case HTML_N_DL:
     case HTML_N_BLQ:
-    case HTML_N_DD:
 	CLOSE_DT;
 	CLOSE_A;
 	if (h_env->envc > 0) {
@@ -4687,7 +4678,7 @@ HTMLtagproc1(struct parsed_tag *tag, str
 		do_blankline(h_env, obuf, envs[h_env->envc].indent, 0,
 			     h_env->limit);
 	}
-	PUSH_ENV_NOINDENT(cmd);
+	PUSH_ENV(cmd);
 	if (parsedtag_exists(tag, ATTR_COMPACT))
 	    envs[h_env->envc].env = HTML_DL_COMPACT;
 	obuf->flag |= RB_IGNORE_P;
@@ -4783,7 +4774,7 @@ HTMLtagproc1(struct parsed_tag *tag, str
 	    (h_env->envc_real < h_env->nenv &&
 	     envs[h_env->envc].env != HTML_DL &&
 	     envs[h_env->envc].env != HTML_DL_COMPACT)) {
-	    PUSH_ENV_NOINDENT(HTML_DL);
+	    PUSH_ENV(HTML_DL);
 	}
 	if (h_env->envc > 0) {
 	    flushline(h_env, obuf,
@@ -4808,12 +4799,14 @@ HTMLtagproc1(struct parsed_tag *tag, str
     case HTML_DD:
 	CLOSE_A;
 	CLOSE_DT;
-	if (envs[h_env->envc].env == HTML_DL ||
-		envs[h_env->envc].env == HTML_DL_COMPACT) {
-	    PUSH_ENV(HTML_DD);
+	if (h_env->envc == 0 ||
+	    (h_env->envc_real < h_env->nenv &&
+	     envs[h_env->envc].env != HTML_DL &&
+	     envs[h_env->envc].env != HTML_DL_COMPACT)) {
+	    PUSH_ENV(HTML_DL);
 	}
 
-	if (h_env->envc > 0 && envs[h_env->envc - 1].env == HTML_DL_COMPACT) {
+	if (envs[h_env->envc].env == HTML_DL_COMPACT) {
 	    if (obuf->pos > envs[h_env->envc].indent)
 		flushline(h_env, obuf, envs[h_env->envc].indent, 0,
 			  h_env->limit);
