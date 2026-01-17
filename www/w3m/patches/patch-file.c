$NetBSD: patch-file.c,v 1.2 2026/01/17 22:35:59 wiz Exp $

* Revert DL/DT/DD related change. It is broken and cannot display
  doc-jp/FAQ.html and http://www.cpm.z80.de/ correctly, for example.
  The old behavior may not be perfect however it works.

--- file.c.orig	2025-08-20 09:32:27.000000000 +0000
+++ file.c
@@ -4299,14 +4299,6 @@ process_idattr(struct readbuffer *obuf, int cmd, struc
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
@@ -4554,7 +4546,6 @@ HTMLtagproc1(struct parsed_tag *tag, struct html_feed_
     case HTML_N_OL:
     case HTML_N_DL:
     case HTML_N_BLQ:
-    case HTML_N_DD:
 	CLOSE_DT;
 	if (cmd == HTML_N_DL)
 	    CLOSE_DD;
@@ -4582,7 +4573,7 @@ HTMLtagproc1(struct parsed_tag *tag, struct html_feed_
 		do_blankline(h_env, obuf, envs[h_env->envc].indent,
 			     h_env->limit);
 	}
-	PUSH_ENV_NOINDENT(cmd);
+	PUSH_ENV(cmd);
 	if (parsedtag_exists(tag, ATTR_COMPACT))
 	    envs[h_env->envc].env = HTML_DL_COMPACT;
 	obuf->flag |= RB_IGNORE_P;
@@ -4679,7 +4670,7 @@ HTMLtagproc1(struct parsed_tag *tag, struct html_feed_
 	    (h_env->envc_real < h_env->nenv &&
 	     envs[h_env->envc].env != HTML_DL &&
 	     envs[h_env->envc].env != HTML_DL_COMPACT)) {
-	    PUSH_ENV_NOINDENT(HTML_DL);
+	    PUSH_ENV(HTML_DL);
 	}
 	if (h_env->envc > 0) {
 	    flushline(h_env, obuf,
@@ -4704,12 +4695,14 @@ HTMLtagproc1(struct parsed_tag *tag, struct html_feed_
     case HTML_DD:
 	CLOSE_A;
 	CLOSE_DT;
-	if (envs[h_env->envc].env == HTML_DL ||
-		envs[h_env->envc].env == HTML_DL_COMPACT) {
+	if (h_env->envc == 0 ||
+	    (h_env->envc_real < h_env->nenv &&
+	     envs[h_env->envc].env != HTML_DL &&
+	     envs[h_env->envc].env != HTML_DL_COMPACT)) {
 	    PUSH_ENV(HTML_DD);
 	}
 
-	if (h_env->envc > 0 && envs[h_env->envc - 1].env == HTML_DL_COMPACT
+	if (envs[h_env->envc - 1].env == HTML_DL_COMPACT
 	    && obuf->pos <= envs[h_env->envc].indent) {
 	    push_spaces(obuf, 1, envs[h_env->envc].indent - obuf->pos);
 	}
