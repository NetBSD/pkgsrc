$NetBSD: patch-server_util__script.c,v 1.1 2016/07/29 11:10:24 wiz Exp $

Fix httpoxy vulnerability.
https://www.apache.org/security/asf-httpoxy-response.txt

--- server/util_script.c.orig	2012-08-21 17:42:49.000000000 +0000
+++ server/util_script.c
@@ -165,6 +165,14 @@ AP_DECLARE(void) ap_add_common_vars(requ
         else if (!strcasecmp(hdrs[i].key, "Content-length")) {
             apr_table_addn(e, "CONTENT_LENGTH", hdrs[i].val);
         }
+        /* HTTP_PROXY collides with a popular envvar used to configure
+         * proxies, don't let clients set/override it.  But, if you must...
+         */
+#ifndef SECURITY_HOLE_PASS_PROXY
+        else if (!strcasecmp(hdrs[i].key, "Proxy")) {
+            ;
+        }
+#endif
         /*
          * You really don't want to disable this check, since it leaves you
          * wide open to CGIs stealing passwords and people viewing them
