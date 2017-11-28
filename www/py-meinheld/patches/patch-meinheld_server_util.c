$NetBSD: patch-meinheld_server_util.c,v 1.3 2017/11/28 12:47:28 wiz Exp $

Add NetBSD support.
https://github.com/mopemope/meinheld/pull/89

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
@@ -59,10 +59,13 @@ int
 enable_cork(client_t *client)
 {
     int on = 1;
-#ifdef linux
+#if defined(linux) || defined(__sun)
     setsockopt(client->fd, IPPROTO_TCP, TCP_CORK, &on, sizeof(on));
 #elif defined(__APPLE__) || defined(__FreeBSD__)
     setsockopt(client->fd, IPPROTO_TCP, TCP_NOPUSH, &on, sizeof(on));
+#elif defined(__NetBSD__)
+    /* not supported */
+    return 1;
 #else
 #error
 #endif
@@ -77,10 +80,13 @@ disable_cork(client_t *client)
     int off = 0;
     int on = 1;
     if(client->use_cork == 1){
-#ifdef linux
+#if defined(linux) || defined(__sun)
         setsockopt(client->fd, IPPROTO_TCP, TCP_CORK, &off, sizeof(off));
 #elif defined(__APPLE__) || defined(__FreeBSD__)
         setsockopt(client->fd, IPPROTO_TCP, TCP_NOPUSH, &off, sizeof(off));
+#elif defined(__NetBSD__)
+    /* not supported */
+    return 1;
 #else
 #error
 #endif
