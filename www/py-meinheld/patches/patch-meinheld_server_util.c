$NetBSD: patch-meinheld_server_util.c,v 1.1 2017/09/30 12:51:57 wiz Exp $

Add NetBSD support.

--- meinheld/server/util.c.orig	2015-09-16 12:56:12.000000000 +0000
+++ meinheld/server/util.c
@@ -7,7 +7,7 @@ setup_listen_sock(int fd)
     int on = 1, r = -1;
 #ifdef linux
     r = setsockopt(fd, IPPROTO_TCP, TCP_DEFER_ACCEPT, &on, sizeof(on));
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
     struct accept_filter_arg afa;
     bzero(&afa, sizeof(afa));
     strcpy(afa.af_name, "httpready");
@@ -63,6 +63,9 @@ enable_cork(client_t *client)
     setsockopt(client->fd, IPPROTO_TCP, TCP_CORK, &on, sizeof(on));
 #elif defined(__APPLE__) || defined(__FreeBSD__)
     setsockopt(client->fd, IPPROTO_TCP, TCP_NOPUSH, &on, sizeof(on));
+#elif defined(__NetBSD__)
+    /* not supported */
+    return 1;
 #else
 #error
 #endif
@@ -81,6 +84,9 @@ disable_cork(client_t *client)
         setsockopt(client->fd, IPPROTO_TCP, TCP_CORK, &off, sizeof(off));
 #elif defined(__APPLE__) || defined(__FreeBSD__)
         setsockopt(client->fd, IPPROTO_TCP, TCP_NOPUSH, &off, sizeof(off));
+#elif defined(__NetBSD__)
+    /* not supported */
+    return 1;
 #else
 #error
 #endif
