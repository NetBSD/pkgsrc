$NetBSD: patch-modules_mappers_mod_rewrite.c,v 1.1.2.2 2011/12/14 02:43:13 sbd Exp $

revision 1209432 from http://svn.apache.org/:
	Fix for additional cases of URL rewriting with ProxyPassMatch or
	RewriteRule, where particular request-URIs could result in undesired
	backend network exposure in some configurations. (CVE-2011-4317)

	Thanks to Prutha Parikh from Qualys for reporting this issue.

	* modules/proxy/mod_proxy.c (proxy_trans): Decline to handle the "*"
	  request-URI.  Fail for cases where r->uri does not begin with a "/".

	* modules/mappers/mod_rewrite.c (hook_uri2file): Likewise.

--- modules/mappers/mod_rewrite.c.orig	2011-09-03 22:54:25.000000000 +0000
+++ modules/mappers/mod_rewrite.c
@@ -4266,6 +4266,18 @@ static int hook_uri2file(request_rec *r)
         return DECLINED;
     }
 
+    if (strcmp(r->unparsed_uri, "*") == 0) {
+        /* Don't apply rewrite rules to "*". */
+        return DECLINED;
+    }
+
+    /* Check that the URI is valid. */
+    if (!r->uri || r->uri[0] != '/') {
+        ap_log_rerror(APLOG_MARK, APLOG_ERR, 0, r,
+                     "Invalid URI in request %s", r->the_request);
+        return HTTP_BAD_REQUEST;
+    }
+
     /*
      *  add the SCRIPT_URL variable to the env. this is a bit complicated
      *  due to the fact that apache uses subrequests and internal redirects
