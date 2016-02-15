$NetBSD: patch-src_mod__authnz__crowd.c,v 1.1 2016/02/15 16:34:32 jperkin Exp $

Support Apache 2.4.

--- src/mod_authnz_crowd.c.orig	2013-09-25 06:41:53.000000000 +0000
+++ src/mod_authnz_crowd.c
@@ -503,7 +503,6 @@ static authn_status authn_crowd_check_pa
 static const authn_provider authn_crowd_provider =
 {
     &authn_crowd_check_password,    /* Callback for HTTP Basic authentication */
-    NULL                            /* Callback for HTTP Digest authentication */
 };
 
 static unsigned int parse_number(const char *string, const char *name, unsigned int min, unsigned int max,
@@ -599,6 +598,83 @@ apr_array_header_t *authnz_crowd_user_gr
  * @param r the current request
  * @return OK, DECLINED, or HTTP_...
  */
+#if AP_MODULE_MAGIC_AT_LEAST(20080403,1)
+static authz_status auth_group_checker(request_rec *r,
+			      const char *require_line,
+			      const void *parsed_require_args) {
+    const char *t, *w;
+    ap_log_rerror(APLOG_MARK, APLOG_DEBUG, 0, r, "mod_authnz_crowd:auth_group_checker");
+
+    authnz_crowd_dir_config *config = get_config(r);
+    if (config == NULL) {
+        return AUTHZ_GENERAL_ERROR;
+    }
+    
+    if (r->user == NULL) {
+        ap_log_rerror(APLOG_MARK, APLOG_CRIT, 0, r, "Authorisation requested, but no user provided.");
+        return AUTHZ_DENIED_NO_USER;
+    }
+
+    apr_array_header_t *user_groups = NULL;
+
+    /* Fetch groups only if actually needed. */
+    if (user_groups == NULL) {
+      user_groups = crowd_user_groups(r->user, r, config->crowd_config);
+      if (user_groups == NULL) {
+	  return AUTHZ_GENERAL_ERROR;
+      }
+    }
+
+    /* Iterate over the groups mentioned in the requirement. */
+    t = require_line;
+    while ((w = ap_getword_conf(r->pool, &t)) && w[0]) {
+      int y;
+      for (y = 0; y < user_groups->nelts; y++) {
+	const char *user_group = APR_ARRAY_IDX(user_groups, y, const char *);
+	ap_log_rerror(APLOG_MARK, APLOG_DEBUG, 0, r,
+		      "auth_group_checker: user_group=%s, required_group=%s", user_group, w);
+	if (strcasecmp(user_group, w) == 0) {
+	  ap_log_rerror(APLOG_MARK, APLOG_INFO, 0, r,
+			"Granted authorisation to '%s' on the basis of membership of '%s'.", r->user, user_group);
+	  return AUTHZ_GRANTED;
+	}
+      }
+
+    }
+
+
+    ap_log_rerror(APLOG_MARK, APLOG_NOTICE, 0, r, "Denied authorisation to '%s'.", r->user);
+    return AUTHZ_DENIED;
+}
+
+static const authz_provider authz_crowd_group_provider = 
+{
+    &auth_group_checker,
+    NULL,
+};
+
+static void register_hooks(apr_pool_t *p)
+{
+    ap_hook_post_config(post_config, NULL, NULL, APR_HOOK_MIDDLE);
+    ap_hook_check_user_id(check_user_id, NULL, NULL, APR_HOOK_FIRST);
+    ap_register_auth_provider(
+        p,
+        AUTHN_PROVIDER_GROUP,
+        "crowd",
+        AUTHN_PROVIDER_VERSION,          
+        &authn_crowd_provider, AP_AUTH_INTERNAL_PER_CONF
+    );
+    
+    // Require crowd-group group1 group2 ...
+    ap_register_auth_provider(
+        p,
+        AUTHZ_PROVIDER_GROUP,
+        "crowd-group",
+        AUTHZ_PROVIDER_VERSION,
+        &authz_crowd_group_provider, AP_AUTH_INTERNAL_PER_CONF
+    );
+}
+#else
 static int auth_checker(request_rec *r) {
     ap_log_rerror(APLOG_MARK, APLOG_DEBUG, 0, r, "mod_authnz_crowd:auth_checker");
 
@@ -678,6 +754,9 @@ static void register_hooks(apr_pool_t *p
     ap_hook_auth_checker(auth_checker, pre_auth_checker, NULL, APR_HOOK_MIDDLE);
 }
 
+#endif
+
+
 module AP_MODULE_DECLARE_DATA authnz_crowd_module =
 {
     STANDARD20_MODULE_STUFF,
