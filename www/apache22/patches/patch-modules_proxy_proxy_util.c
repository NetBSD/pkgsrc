$NetBSD: patch-modules_proxy_proxy_util.c,v 1.1 2015/11/12 15:21:51 prlw1 Exp $

Fix a regression with 2.2.31 that caused inherited workers to
use a different scoreboard slot then the original one.

https://svn.apache.org/viewvc?view=revision&revision=1700408

--- modules/proxy/proxy_util.c.orig	2015-07-15 16:10:27.000000000 +0000
+++ modules/proxy/proxy_util.c
@@ -1460,6 +1460,7 @@ PROXY_DECLARE(const char *) ap_proxy_add
     (*worker)->flush_packets = flush_off;
     (*worker)->flush_wait = PROXY_FLUSH_WAIT;
     (*worker)->smax = -1;
+    (*worker)->server = conf->s;
     /* Increase the total worker count */
     proxy_lb_workers++;
     init_conn_pool(p, *worker);
@@ -1807,6 +1808,7 @@ PROXY_DECLARE(void*) ap_proxy_set_scoreb
                                                 server_rec *server)
 {
     if (ap_scoreboard_image && !worker->s) {
+        server_rec *id_server;
         int i = 0;
         proxy_worker_stat *free_slot = NULL;
         proxy_worker_stat *s;
@@ -1824,14 +1826,20 @@ PROXY_DECLARE(void*) ap_proxy_set_scoreb
             apr_md5_update(&ctx, (unsigned char *)balancer->name,
                            strlen(balancer->name));
         }
-        if (server) {
+        if (worker->server) {
+            id_server = worker->server;
+        }
+        else {
+            id_server = server;
+        }
+        if (id_server) {
             server_addr_rec *addr;
             /* Assumes the unique identifier of a vhost is its address(es)
              * plus the ServerName:Port. Should two or more vhosts have this
              * same identifier, the first one would always be elected to
              * handle the requests, so this shouldn't be an issue...
              */
-            for (addr = server->addrs; addr; addr = addr->next) {
+            for (addr = id_server->addrs; addr; addr = addr->next) {
                 char host_ip[64]; /* for any IPv[46] string */
                 apr_sockaddr_ip_getbuf(host_ip, sizeof host_ip,
                                        addr->host_addr);
@@ -1840,10 +1848,10 @@ PROXY_DECLARE(void*) ap_proxy_set_scoreb
                 apr_md5_update(&ctx, (unsigned char *)&addr->host_port,
                                sizeof(addr->host_port));
             }
-            apr_md5_update(&ctx, (unsigned char *)server->server_hostname,
-                           strlen(server->server_hostname));
-            apr_md5_update(&ctx, (unsigned char *)&server->port,
-                           sizeof(server->port));
+            apr_md5_update(&ctx, (unsigned char *)id_server->server_hostname,
+                           strlen(id_server->server_hostname));
+            apr_md5_update(&ctx, (unsigned char *)&id_server->port,
+                           sizeof(id_server->port));
         }
         apr_md5_final(digest, &ctx);
 
