$NetBSD: patch-server_util.c,v 1.1.2.2 2011/11/12 04:25:37 sbd Exp $

fix for http://secunia.com/advisories/45793/
snarfed (with adjustment regarding location) from
http://svn.apache.org/viewvc/httpd/httpd/trunk/server/util.c?r1=1198940&r2=1198939&pathrev=1198940

--- server/util.c.orig	2011-05-19 02:17:37.000000000 +0000
+++ server/util.c
@@ -391,6 +391,8 @@ AP_DECLARE(char *) ap_pregsub(apr_pool_t
             len++;
         }
         else if (no < nmatch && pmatch[no].rm_so < pmatch[no].rm_eo) {
+            if (APR_SIZE_MAX - len <= pmatch[no].rm_eo - pmatch[no].rm_so)
+                return APR_ENOMEM;
             len += pmatch[no].rm_eo - pmatch[no].rm_so;
         }
 
