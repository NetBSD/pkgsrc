--- ../ngx_devel_kit-0.3.4/src/ndk_set_var.c.orig	2026-07-07 14:27:09.629438000 -0400
+++ ../ngx_devel_kit-0.3.4/src/ndk_set_var.c	2026-07-07 14:27:54.282783000 -0400
@@ -452,7 +452,6 @@
     ngx_http_variable_t                 *v;
     ndk_http_rewrite_loc_conf_t         *rlcf;
     ngx_http_script_var_code_t          *vcode;
-    ngx_http_script_var_handler_code_t  *vhcode;
 
     v = info->v;
     cf = info->cf;
@@ -460,20 +459,6 @@
 
     if (ndk_set_var_filter(cf, rlcf, filter) != NGX_CONF_OK) {
         return NGX_CONF_ERROR;
-    }
-
-    if (v->set_handler) {
-        vhcode = ngx_http_script_start_code(cf->pool, &rlcf->codes,
-                                   sizeof(ngx_http_script_var_handler_code_t));
-        if (vhcode == NULL) {
-            return NGX_CONF_ERROR;
-        }
-
-        vhcode->code = ngx_http_script_var_set_handler_code;
-        vhcode->handler = v->set_handler;
-        vhcode->data = v->data;
-
-        return NGX_CONF_OK;
     }
 
     vcode = ngx_http_script_start_code(cf->pool, &rlcf->codes,
