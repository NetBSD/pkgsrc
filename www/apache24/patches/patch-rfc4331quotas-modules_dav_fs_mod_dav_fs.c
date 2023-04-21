$NetBSD: patch-rfc4331quotas-modules_dav_fs_mod_dav_fs.c,v 1.1 2023/04/21 13:52:33 manu Exp $

RFC4331 quotas from upstream trunk
http://svn.apache.org/viewvc?view=revision&revision=1907974
http://svn.apache.org/viewvc?view=revision&revision=1907984
http://svn.apache.org/viewvc?view=revision&revision=1907989
http://svn.apache.org/viewvc?view=revision&revision=1908143
http://svn.apache.org/viewvc?view=revision&revision=1908144

--- modules/dav/fs/mod_dav_fs.c	(revision 1907973)
+++ modules/dav/fs/mod_dav_fs.c	(revision 1907974)
@@ -15,13 +15,20 @@
  */
 
 #include "httpd.h"
 #include "http_config.h"
+#include "http_request.h"
 #include "apr_strings.h"
 
 #include "mod_dav.h"
 #include "repos.h"
 
+/* per-dir configuration */
+typedef struct {
+    const char *dir;
+    apr_off_t quota;
+} dav_fs_dir_conf;
+
 /* per-server configuration */
 typedef struct {
     const char *lockdb_path;
 
@@ -36,8 +43,62 @@
     conf = ap_get_module_config(r->server->module_config, &dav_fs_module);
     return conf->lockdb_path;
 }
 
+static const command_rec dav_fs_cmds[];
+
+dav_error *dav_fs_get_quota(const request_rec *r, const char *path,
+                            apr_off_t *quota_bytes)
+{
+    dav_fs_dir_conf *conf = NULL;
+    dav_error *err = NULL;
+    const char *request_path;
+    request_rec *rr;
+    int status;
+
+    request_path = ap_make_dirstr_parent(r->pool, r->filename);
+
+    /* 
+     * Uses's request's per directry configuration if possible, for
+     * efficiency sake.
+     */
+    if (!strcmp(path, request_path)) {
+        conf = ap_get_module_config(r->per_dir_config, &dav_fs_module);
+        *quota_bytes = conf->quota;
+        goto out;
+    }
+
+    /* 
+     * We need for a per directory configuration from a random path
+     * not tied to current request, for e.g. COPY or MOVE destination.
+     * This is done through a subrequest, with just rr->filename
+     * changed to target path.
+     */
+    rr = ap_sub_req_method_uri(r->method, r->uri, r, r->output_filters);
+    if (!rr || rr->status != HTTP_OK) {
+        err = dav_new_error(r->pool,
+                            rr ? rr->status : HTTP_INTERNAL_SERVER_ERROR,
+                            0, 0,
+                            "quota configuration subrequest failed");
+        *quota_bytes = DAV_FS_BYTES_ERROR;
+        goto out;
+    }
+
+    rr->filename = apr_pstrdup(r->pool, path);
+    if ((status = ap_directory_walk(rr)) != OK)  {
+        err = dav_new_error(r->pool, status, 0, 0,
+                            "quota configuration tree walk failed");
+        *quota_bytes = DAV_FS_BYTES_ERROR;
+        goto out;
+    }
+
+    conf = ap_get_module_config(rr->per_dir_config, &dav_fs_module);
+    *quota_bytes = conf->quota;
+
+out:
+    return err;
+}
+
 static void *dav_fs_create_server_config(apr_pool_t *p, server_rec *s)
 {
     return apr_pcalloc(p, sizeof(dav_fs_server_conf));
 }
@@ -56,8 +117,38 @@
 
     return newconf;
 }
 
+static void *dav_fs_create_dir_config(apr_pool_t *p, char *dir)
+{
+    /* NOTE: dir==NULL creates the default per-dir config */
+
+    dav_fs_dir_conf *conf;
+
+    conf = (dav_fs_dir_conf *)apr_pcalloc(p, sizeof(*conf));
+    conf->dir = apr_pstrdup(p, dir);
+    conf->quota = DAV_FS_QUOTA_UNSET;
+
+    return conf;
+}
+
+static void *dav_fs_merge_dir_config(apr_pool_t *p, void *base, void *overrides)
+{
+    dav_fs_dir_conf *parent = base;
+    dav_fs_dir_conf *child = overrides;
+    dav_fs_dir_conf *newconf =
+        (dav_fs_dir_conf *)apr_pcalloc(p, sizeof(*newconf));
+
+    newconf->dir = child->dir;
+
+    if (child->quota != DAV_FS_QUOTA_UNSET)
+        newconf->quota = child->quota;
+    else
+        newconf->quota = parent->quota;
+
+    return newconf;
+}
+
 /*
  * Command handler for the DAVLockDB directive, which is TAKE1
  */
 static const char *dav_fs_cmd_davlockdb(cmd_parms *cmd, void *config,
@@ -75,14 +166,37 @@
 
     return NULL;
 }
 
+/*
+ * Command handler for the DAVquota directive, which is TAKE1
+ */
+static const char *dav_fs_cmd_quota(cmd_parms *cmd, void *config,
+                                    const char *bytes)
+{
+    dav_fs_dir_conf *conf = (dav_fs_dir_conf *)config;
+
+    if (!strcasecmp(bytes, "Off"))
+        conf->quota = DAV_FS_QUOTA_OFF;
+    else if (!strcasecmp(bytes, "None"))
+        conf->quota = DAV_FS_QUOTA_NONE;
+    else
+        conf->quota = atol(bytes);
+
+    return NULL;
+}
+
+
 static const command_rec dav_fs_cmds[] =
 {
     /* per server */
     AP_INIT_TAKE1("DAVLockDB", dav_fs_cmd_davlockdb, NULL, RSRC_CONF,
                   "specify a lock database"),
 
+    /* per directory */
+    AP_INIT_TAKE1("DAVquota", dav_fs_cmd_quota, NULL, ACCESS_CONF|RSRC_CONF,
+                  "specify a directory quota"),
+
     { NULL }
 };
 
 static void register_hooks(apr_pool_t *p)
@@ -91,17 +205,19 @@
                              APR_HOOK_MIDDLE);
     dav_hook_find_liveprop(dav_fs_find_liveprop, NULL, NULL, APR_HOOK_MIDDLE);
     dav_hook_insert_all_liveprops(dav_fs_insert_all_liveprops, NULL, NULL,
                                   APR_HOOK_MIDDLE);
+    dav_hook_method_precondition(dav_fs_method_precondition, NULL, NULL,
+                                  APR_HOOK_MIDDLE);
 
     dav_fs_register(p);
 }
 
 AP_DECLARE_MODULE(dav_fs) =
 {
     STANDARD20_MODULE_STUFF,
-    NULL,                        /* dir config creater */
-    NULL,                        /* dir merger --- default is to override */
+    dav_fs_create_dir_config,    /* dir config */
+    dav_fs_merge_dir_config,     /* merger dir config */
     dav_fs_create_server_config, /* server config */
     dav_fs_merge_server_config,  /* merge server config */
     dav_fs_cmds,                 /* command table */
     register_hooks,              /* register hooks */
Index: modules/dav/fs/mod_dav_fs.dsp
===================================================================
