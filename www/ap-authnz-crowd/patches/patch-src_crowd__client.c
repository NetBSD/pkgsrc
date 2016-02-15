$NetBSD: patch-src_crowd__client.c,v 1.1 2016/02/15 16:34:32 jperkin Exp $

Support Apache 2.4.

--- src/crowd_client.c.orig	2013-11-20 23:34:10.000000000 +0000
+++ src/crowd_client.c
@@ -613,9 +613,15 @@ static char *make_app_cache_key(const re
 }
 
 static char *make_session_cache_key(const char *token, const char *forwarded_for, const request_rec *r, const crowd_config *config) {
+#if AP_MODULE_MAGIC_AT_LEAST(20080403,1)
+    return log_ralloc(r, apr_psprintf(r->pool, "%s\037%s\037%s\037%s\037%s", token,
+        forwarded_for == NULL ? "" : forwarded_for, r->connection->client_ip, config->crowd_app_name,
+        config->crowd_url));
+#else
     return log_ralloc(r, apr_psprintf(r->pool, "%s\037%s\037%s\037%s\037%s", token,
         forwarded_for == NULL ? "" : forwarded_for, r->connection->remote_ip, config->crowd_app_name,
         config->crowd_url));
+#endif
 }
 
 /*==========================
@@ -746,9 +752,15 @@ static bool handle_crowd_create_session_
 }
 
 static const char *get_validation_factors(const request_rec *r, const char *forwarded_for) {
+#if AP_MODULE_MAGIC_AT_LEAST(20080403,1)
+    const char *payload_beginning = log_ralloc(r, apr_pstrcat(r->pool,
+        "<validation-factors><validation-factor><name>remote_address</name><value>", r->connection->client_ip,
+        "</value></validation-factor>", NULL));
+#else
     const char *payload_beginning = log_ralloc(r, apr_pstrcat(r->pool,
         "<validation-factors><validation-factor><name>remote_address</name><value>", r->connection->remote_ip,
         "</value></validation-factor>", NULL));
+#endif
     if (payload_beginning == NULL) {
         return NULL;
     }
@@ -845,7 +857,7 @@ static const char *make_validate_session
 
     char *url = log_ralloc(r, apr_pstrcat(r->pool, urlWithoutToken, escapedToken, NULL));
 
-    curl_free(escapedToken);
+    curl_free((void *)escapedToken);
 
     return url;
 }
