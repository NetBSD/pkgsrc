$NetBSD: patch-modules_proxy_mod_proxy.c,v 1.3 2015/11/12 15:21:51 prlw1 Exp $

Fix a regression with 2.2.31 that caused inherited workers to
use a different scoreboard slot then the original one.

https://svn.apache.org/viewvc?view=revision&revision=1700408

--- modules/proxy/mod_proxy.c.orig	2015-06-05 16:50:47.000000000 +0000
+++ modules/proxy/mod_proxy.c
@@ -1129,6 +1129,7 @@ static void * create_proxy_config(apr_po
     ps->badopt = bad_error;
     ps->badopt_set = 0;
     ps->pool = p;
+    ps->s = s;
 
     return ps;
 }
@@ -1172,6 +1173,7 @@ static void * merge_proxy_config(apr_poo
     ps->proxy_status = (overrides->proxy_status_set == 0) ? base->proxy_status : overrides->proxy_status;
     ps->proxy_status_set = overrides->proxy_status_set || base->proxy_status_set;
     ps->pool = p;
+    ps->s = overrides->s;
     return ps;
 }
 
