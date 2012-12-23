$NetBSD: patch-modules_ssl_ssl__engine__kernel.c,v 1.1 2012/12/23 21:32:42 spz Exp $

https://issues.apache.org/bugzilla/show_bug.cgi?id=49491

--- ./modules/ssl/ssl_engine_kernel.c.orig	2012-08-20 15:53:11.000000000 +0000
+++ ./modules/ssl/ssl_engine_kernel.c	2012-12-21 08:18:57.000000000 +0000
@@ -136,7 +136,7 @@ int ssl_hook_ReadReq(request_rec *r)
         if (rv != APR_SUCCESS || scope_id) {
             return HTTP_BAD_REQUEST;
         }
-        if (strcmp(host, servername)) {
+        if (strcasecmp(host, servername)) {
             ap_log_error(APLOG_MARK, APLOG_ERR, 0, r->server,
                         "Hostname %s provided via SNI and hostname %s provided"
                         " via HTTP are different", servername, host);
