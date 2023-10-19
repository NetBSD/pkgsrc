$NetBSD: patch-modules_filters_mod_substitute.c,v 1.2 2023/10/19 14:22:02 wiz Exp $

expr= support in RHS, from upstream trunk

--- modules/filters/mod_substitute.c.orig	2021-04-18 19:11:48.000000000 +0000
+++ modules/filters/mod_substitute.c
@@ -30,6 +30,7 @@
 #include "util_varbuf.h"
 #include "apr_buckets.h"
 #include "http_request.h"
+#include "ap_expr.h"
 #define APR_WANT_STRFUNC
 #include "apr_want.h"
 
@@ -52,6 +53,7 @@ typedef struct subst_pattern_t {
     apr_size_t patlen;
     int flatten;
     const char *from;
+    ap_expr_info_t* expr_replacement;
 } subst_pattern_t;
 
 typedef struct {
@@ -69,6 +71,11 @@ typedef struct {
     apr_pool_t *tpool;
 } substitute_module_ctx;
 
+typedef struct { 
+    const char **expcache;
+    int *expcache_len;
+} subst_req_t;
+
 static void *create_substitute_dcfg(apr_pool_t *p, char *d)
 {
     subst_dir_conf *dcfg =
@@ -97,7 +104,7 @@ static void *merge_substitute_dcfg(apr_p
      * In later 2.2 and 2.4 versions, SubstituteInheritBefore may be toggled
      * 'on' to follow the corrected/expected behavior, without violating POLS.
      */
-    if (a->inherit_before == 1) {
+    if (a->inherit_before) {
         a->patterns = apr_array_append(p, base->patterns,
                                           over->patterns);
     }
@@ -137,11 +144,14 @@ static apr_status_t do_pattmatch(ap_filt
     struct ap_varbuf vb;
     apr_bucket *b;
     apr_bucket *tmp_b;
+    subst_pattern_t *script;
 
     subst_dir_conf *cfg =
     (subst_dir_conf *) ap_get_module_config(f->r->per_dir_config,
                                              &substitute_module);
-    subst_pattern_t *script;
+    subst_req_t *rconf = 
+    (subst_req_t*) ap_get_module_config(f->r->request_config, 
+                                        &substitute_module);
 
     APR_BRIGADE_INSERT_TAIL(mybb, inb);
     ap_varbuf_init(pool, &vb, 0);
@@ -155,6 +165,16 @@ static apr_status_t do_pattmatch(ap_filt
        force_quick = 1;
     }
     for (i = 0; i < cfg->patterns->nelts; i++) {
+        const char *replacement = script->replacement;
+        apr_size_t replen = script->replen;
+        if (script->expr_replacement) { 
+            if (!rconf) { 
+                rconf = apr_pcalloc(f->r->pool, sizeof(*rconf));
+                rconf->expcache     = apr_pcalloc(f->r->pool, sizeof(const char*) * cfg->patterns->nelts);
+                rconf->expcache_len = apr_pcalloc(f->r->pool, sizeof(int) * cfg->patterns->nelts);
+                ap_set_module_config(f->r->request_config, &substitute_module, rconf);
+            }
+        }
         for (b = APR_BRIGADE_FIRST(mybb);
              b != APR_BRIGADE_SENTINEL(mybb);
              b = APR_BUCKET_NEXT(b)) {
@@ -187,12 +207,26 @@ static apr_status_t do_pattmatch(ap_filt
                      * line length reaches max_line_length.
                      */
                     apr_size_t space_left = cfg->max_line_length;
-                    apr_size_t repl_len = strlen(script->replacement);
                     while ((repl = apr_strmatch(script->pattern, buff, bytes)))
                     {
+                        
+                        if (!have_match && script->expr_replacement) { 
+                            if (!rconf->expcache[i]) {
+                                const char *err = NULL;
+                                rconf->expcache[i] = ap_expr_str_exec(f->r, script->expr_replacement, &err);
+                                if (err) { 
+                                    ap_log_rerror(APLOG_MARK, APLOG_ERR, 0, f->r, "error evaluating expression: %s", err);
+                                    return APR_EINVAL;
+                                }
+                                rconf->expcache_len[i] = strlen(rconf->expcache[i]);
+                            }
+                            replacement = rconf->expcache[i];
+                            replen      = rconf->expcache_len[i];
+                        }
+
                         ap_log_rerror(APLOG_MARK, APLOG_TRACE8, 0, f->r,
                                       "Matching found, result: '%s'",
-                                      script->replacement);
+                                      replacement);
                         have_match = 1;
                         /* get offset into buff for pattern */
                         len = (apr_size_t) (repl - buff);
@@ -205,10 +239,10 @@ static apr_status_t do_pattmatch(ap_filt
                              * are constanting allocing space and copying
                              * strings.
                              */
-                            if (vb.strlen + len + repl_len > cfg->max_line_length)
+                            if (vb.strlen + len + replen > cfg->max_line_length)
                                 return APR_ENOMEM;
                             ap_varbuf_strmemcat(&vb, buff, len);
-                            ap_varbuf_strmemcat(&vb, script->replacement, repl_len);
+                            ap_varbuf_strmemcat(&vb, replacement, replen);
                         }
                         else {
                             /*
@@ -217,9 +251,9 @@ static apr_status_t do_pattmatch(ap_filt
                              * Check if we still have space for this string and
                              * the replacement string.
                              */
-                            if (space_left < len + repl_len)
+                            if (space_left < len + replen)
                                 return APR_ENOMEM;
-                            space_left -= len + repl_len;
+                            space_left -= len + replen;
                             /*
                              * We now split off the string before the match
                              * as its own bucket, then isolate the matched
@@ -230,8 +264,8 @@ static apr_status_t do_pattmatch(ap_filt
                              * Finally, we create a bucket that contains the
                              * replacement...
                              */
-                            tmp_b = apr_bucket_transient_create(script->replacement,
-                                      script->replen,
+                            tmp_b = apr_bucket_transient_create(replacement,
+                                      replen,
                                       f->r->connection->bucket_alloc);
                             /* ... and insert it */
                             APR_BUCKET_INSERT_BEFORE(b, tmp_b);
@@ -282,6 +316,20 @@ static apr_status_t do_pattmatch(ap_filt
                     while (!ap_regexec_len(script->regexp, pos, left,
                                        AP_MAX_REG_MATCH, regm, 0)) {
                         apr_status_t rv;
+                        if (!have_match && script->expr_replacement) {
+                            if (!rconf->expcache[i]) {
+                                const char *err = NULL;
+                                rconf->expcache[i] = ap_expr_str_exec(f->r, script->expr_replacement, &err);
+                                if (err) {
+                                    ap_log_rerror(APLOG_MARK, APLOG_ERR, 0, f->r, "error evaluating expression: %s", err);
+                                    return APR_EGENERAL;
+                                }
+                                rconf->expcache_len[i] = strlen(rconf->expcache[i]);
+                            }
+                            replacement = rconf->expcache[i];
+                            replen      = rconf->expcache_len[i];
+                        }
+
                         ap_log_rerror(APLOG_MARK, APLOG_TRACE8, 0, f->r,
                                       "Matching found");
                         have_match = 1;
@@ -296,7 +344,7 @@ static apr_status_t do_pattmatch(ap_filt
                             if (regm[0].rm_so > 0)
                                 ap_varbuf_strmemcat(&vb, pos, regm[0].rm_so);
                             /* add replacement string, last argument is unsigned! */
-                            rv = ap_varbuf_regsub(&vb, script->replacement, pos,
+                            rv = ap_varbuf_regsub(&vb, replacement, pos,
                                                   AP_MAX_REG_MATCH, regm,
                                                   cfg->max_line_length - vb.strlen);
                             if (rv != APR_SUCCESS)
@@ -311,7 +359,7 @@ static apr_status_t do_pattmatch(ap_filt
                                 return APR_ENOMEM;
                             space_left -= regm[0].rm_so;
                             rv = ap_pregsub_ex(pool, &repl,
-                                               script->replacement, pos,
+                                               replacement, pos,
                                                AP_MAX_REG_MATCH, regm,
                                                space_left);
                             if (rv != APR_SUCCESS)
@@ -464,6 +512,7 @@ static apr_status_t substitute_filter(ap
             }
             APR_BUCKET_REMOVE(b);
             APR_BRIGADE_INSERT_TAIL(ctx->passbb, b);
+            ap_remove_output_filter(f);
         }
         /*
          * No need to handle FLUSH buckets separately as we call
@@ -694,6 +743,18 @@ static const char *set_pattern(cmd_parms
 
     nscript->replacement = to;
     nscript->replen = strlen(to);
+
+    if (!strncasecmp(to, "expr=", 5)) { 
+        const char *err;
+        nscript->expr_replacement = ap_expr_parse_cmd(cmd, to+5,
+                                          AP_EXPR_FLAG_STRING_RESULT,
+                                          &err, NULL);
+        if (err) {
+            return apr_pstrcat(cmd->pool,
+                    "Can't parse value expression : ", err, NULL);
+        }
+    } 
+
     nscript->flatten = flatten;
 
     return NULL;
