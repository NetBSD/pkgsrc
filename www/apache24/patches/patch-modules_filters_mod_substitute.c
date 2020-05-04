$NetBSD: patch-modules_filters_mod_substitute.c,v 1.1 2020/05/04 12:26:37 manu Exp $

expr= support in RHS, from upstream trunk

--- ./modules/filters/mod_substitute.c.orig
+++ ./modules/filters/mod_substitute.c
@@ -29,8 +29,9 @@
 #include "util_filter.h"
 #include "util_varbuf.h"
 #include "apr_buckets.h"
 #include "http_request.h"
+#include "ap_expr.h"
 #define APR_WANT_STRFUNC
 #include "apr_want.h"
 
 /*
@@ -51,8 +52,9 @@
     apr_size_t replen;
     apr_size_t patlen;
     int flatten;
     const char *from;
+    ap_expr_info_t* expr_replacement;
 } subst_pattern_t;
 
 typedef struct {
     apr_array_header_t *patterns;
@@ -68,8 +70,13 @@
     apr_bucket_brigade *pattbb;
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
         (subst_dir_conf *) apr_palloc(p, sizeof(subst_dir_conf));
@@ -96,9 +103,9 @@
      * was to apply inherited subst patterns after locally scoped patterns.
      * In later 2.2 and 2.4 versions, SubstituteInheritBefore may be toggled
      * 'on' to follow the corrected/expected behavior, without violating POLS.
      */
-    if (a->inherit_before == 1) {
+    if (a->inherit_before) {
         a->patterns = apr_array_append(p, base->patterns,
                                           over->patterns);
     }
     else {
@@ -136,13 +143,16 @@
     const char *buff;
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
 
@@ -154,8 +164,18 @@
     if (cfg->patterns->nelts == 1) {
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
             if (APR_BUCKET_IS_METADATA(b)) {
@@ -186,14 +206,28 @@
                      * space_left counts how many bytes we have left until the
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
                         if (script->flatten && !force_quick) {
@@ -204,23 +238,23 @@
                              * contain and use them. This is slow, since we
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
                              * The string before the match but after the
                              * previous match (if any) has length 'len'.
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
                              * string and delete it.
@@ -229,10 +263,10 @@
                             /*
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
                         }
@@ -281,8 +315,22 @@
                     apr_size_t space_left = cfg->max_line_length;
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
                         if (script->flatten && !force_quick) {
@@ -295,9 +343,9 @@
                             /* copy bytes before the match */
                             if (regm[0].rm_so > 0)
                                 ap_varbuf_strmemcat(&vb, pos, regm[0].rm_so);
                             /* add replacement string, last argument is unsigned! */
-                            rv = ap_varbuf_regsub(&vb, script->replacement, pos,
+                            rv = ap_varbuf_regsub(&vb, replacement, pos,
                                                   AP_MAX_REG_MATCH, regm,
                                                   cfg->max_line_length - vb.strlen);
                             if (rv != APR_SUCCESS)
                                 return rv;
@@ -310,9 +358,9 @@
                             if (space_left <= regm[0].rm_so)
                                 return APR_ENOMEM;
                             space_left -= regm[0].rm_so;
                             rv = ap_pregsub_ex(pool, &repl,
-                                               script->replacement, pos,
+                                               replacement, pos,
                                                AP_MAX_REG_MATCH, regm,
                                                space_left);
                             if (rv != APR_SUCCESS)
                                 return rv;
@@ -462,8 +510,9 @@
                 apr_brigade_cleanup(ctx->linebb);
             }
             APR_BUCKET_REMOVE(b);
             APR_BRIGADE_INSERT_TAIL(ctx->passbb, b);
+            ap_remove_output_filter(f);
         }
         /*
          * No need to handle FLUSH buckets separately as we call
          * ap_pass_brigade anyway at the end of the loop.
@@ -690,8 +739,20 @@
     }
 
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
 }
