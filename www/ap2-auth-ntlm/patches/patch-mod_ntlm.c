$NetBSD: patch-mod_ntlm.c,v 1.1.1.1 2008/10/17 19:24:10 sborrill Exp $
Add Apache 2.2 compatibility
--- mod_ntlm.c.orig	2008-10-17 20:18:13.000000000 +0100
+++ mod_ntlm.c	2008-10-17 20:18:13.000000000 +0100
@@ -671,7 +671,7 @@
         return NULL;
     }
 
-    apr_pool_sub_make(&sp,p,NULL);
+    apr_pool_create_ex(&sp,p,NULL,NULL);
 
     while (!(ap_cfg_getline(l, MAX_STRING_LEN, f))) {
         if ((l[0] == '#') || (!l[0]))
