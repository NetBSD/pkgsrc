$NetBSD: patch-modules_proxy_mod_proxy.h,v 1.1 2015/11/12 15:21:51 prlw1 Exp $

Fix a regression with 2.2.31 that caused inherited workers to
use a different scoreboard slot then the original one.

https://svn.apache.org/viewvc?view=revision&revision=1700408

--- modules/proxy/mod_proxy.h.orig	2015-07-15 16:10:27.000000000 +0000
+++ modules/proxy/mod_proxy.h
@@ -193,6 +193,7 @@ typedef struct {
     } proxy_status;             /* Status display options */
     char proxy_status_set;
     apr_pool_t *pool;           /* Pool used for allocating this struct */
+    server_rec *s;              /* The server_rec where this configuration was created in */
 } proxy_server_conf;
 
 
@@ -369,6 +370,7 @@ struct proxy_worker {
     char            disablereuse_set;
     apr_interval_time_t conn_timeout;
     char            conn_timeout_set;
+    server_rec      *server;    /* The server_rec where this configuration was created in */
 };
 
 /*
