$NetBSD: patch-modules_lua_mod_lua.c,v 1.1 2015/01/22 20:02:37 tron Exp $

Fix for CVE-2014-8109 taken from here:

https://svn.apache.org/viewvc?view=revision&revision=1642861

--- modules/lua/mod_lua.c.orig	2014-06-22 19:16:21.000000000 +0100
+++ modules/lua/mod_lua.c	2015-01-22 19:43:32.000000000 +0000
@@ -66,9 +66,13 @@
     const char *file_name;
     const char *function_name;
     ap_lua_vm_spec *spec;
-    apr_array_header_t *args;
 } lua_authz_provider_spec;
 
+typedef struct {
+    lua_authz_provider_spec *spec;
+    apr_array_header_t *args;
+} lua_authz_provider_func;
+
 apr_hash_t *lua_authz_providers;
 
 typedef struct
@@ -1692,6 +1696,7 @@
 {
     const char *provider_name;
     lua_authz_provider_spec *spec;
+    lua_authz_provider_func *func = apr_pcalloc(cmd->pool, sizeof(lua_authz_provider_func));
 
     apr_pool_userdata_get((void**)&provider_name, AUTHZ_PROVIDER_NAME_NOTE,
                           cmd->temp_pool);
@@ -1699,16 +1704,17 @@
 
     spec = apr_hash_get(lua_authz_providers, provider_name, APR_HASH_KEY_STRING);
     ap_assert(spec != NULL);
+    func->spec = spec;
 
     if (require_line && *require_line) {
         const char *arg;
-        spec->args = apr_array_make(cmd->pool, 2, sizeof(const char *));
+        func->args = apr_array_make(cmd->pool, 2, sizeof(const char *));
         while ((arg = ap_getword_conf(cmd->pool, &require_line)) && *arg) {
-            APR_ARRAY_PUSH(spec->args, const char *) = arg;
+            APR_ARRAY_PUSH(func->args, const char *) = arg;
         }
     }
 
-    *parsed_require_line = spec;
+    *parsed_require_line = func;
     return NULL;
 }
 
@@ -1722,7 +1728,8 @@
                                                          &lua_module);
     const ap_lua_dir_cfg *cfg = ap_get_module_config(r->per_dir_config,
                                                      &lua_module);
-    const lua_authz_provider_spec *prov_spec = parsed_require_line;
+    const lua_authz_provider_func *prov_func = parsed_require_line;
+    const lua_authz_provider_spec *prov_spec = prov_func->spec;
     int result;
     int nargs = 0;
 
@@ -1744,19 +1751,19 @@
         return AUTHZ_GENERAL_ERROR;
     }
     ap_lua_run_lua_request(L, r);
-    if (prov_spec->args) {
+    if (prov_func->args) {
         int i;
-        if (!lua_checkstack(L, prov_spec->args->nelts)) {
+        if (!lua_checkstack(L, prov_func->args->nelts)) {
             ap_log_rerror(APLOG_MARK, APLOG_ERR, 0, r, APLOGNO(02315)
                           "Error: authz provider %s: too many arguments", prov_spec->name);
             ap_lua_release_state(L, spec, r);
             return AUTHZ_GENERAL_ERROR;
         }
-        for (i = 0; i < prov_spec->args->nelts; i++) {
-            const char *arg = APR_ARRAY_IDX(prov_spec->args, i, const char *);
+        for (i = 0; i < prov_func->args->nelts; i++) {
+            const char *arg = APR_ARRAY_IDX(prov_func->args, i, const char *);
             lua_pushstring(L, arg);
         }
-        nargs = prov_spec->args->nelts;
+        nargs = prov_func->args->nelts;
     }
     if (lua_pcall(L, 1 + nargs, 1, 0)) {
         const char *err = lua_tostring(L, -1);
