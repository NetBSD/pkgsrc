$NetBSD: patch-server_util.c,v 1.1.4.1 2012/01/18 19:54:36 tron Exp $

fix for http://secunia.com/advisories/45793/
http://svn.apache.org/viewvc/httpd/httpd/branches/2.2.x/server/util.c?r1=1124515&r2=1227280
modulo we have apr 1.3 and can use APR_SIZE_MAX and APR_ENOMEM

--- server/util.c.orig	2011-05-19 02:17:37.000000000 +0000
+++ server/util.c
@@ -366,7 +366,7 @@ AP_DECLARE(char *) ap_pregsub(apr_pool_t
     char *dest, *dst;
     char c;
     size_t no;
-    int len;
+    apr_size_t len;
 
     if (!source)
         return NULL;
@@ -391,6 +391,8 @@ AP_DECLARE(char *) ap_pregsub(apr_pool_t
             len++;
         }
         else if (no < nmatch && pmatch[no].rm_so < pmatch[no].rm_eo) {
+            if (APR_SIZE_MAX - len <= pmatch[no].rm_eo - pmatch[no].rm_so)
+                return APR_ENOMEM;
             len += pmatch[no].rm_eo - pmatch[no].rm_so;
         }
 
