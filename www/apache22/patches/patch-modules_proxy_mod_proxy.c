$NetBSD: patch-modules_proxy_mod_proxy.c,v 1.1.2.2 2011/12/14 02:43:13 sbd Exp $

revision 1209432 from http://svn.apache.org/:
        Fix for additional cases of URL rewriting with ProxyPassMatch or
        RewriteRule, where particular request-URIs could result in undesired
        backend network exposure in some configurations. (CVE-2011-4317)

        Thanks to Prutha Parikh from Qualys for reporting this issue.

        * modules/proxy/mod_proxy.c (proxy_trans): Decline to handle the "*"
          request-URI.  Fail for cases where r->uri does not begin with a "/".

        * modules/mappers/mod_rewrite.c (hook_uri2file): Likewise.

--- modules/proxy/mod_proxy.c.orig	2010-10-07 18:51:18.000000000 +0000
+++ modules/proxy/mod_proxy.c
@@ -566,6 +566,18 @@ static int proxy_trans(request_rec *r)
         return OK;
     }
 
+    if (strcmp(r->unparsed_uri, "*") == 0) {
+        /* "*" cannot be proxied. */
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
     /* XXX: since r->uri has been manipulated already we're not really
      * compliant with RFC1945 at this point.  But this probably isn't
      * an issue because this is a hybrid proxy/origin server.
