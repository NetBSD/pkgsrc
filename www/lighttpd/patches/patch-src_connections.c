$NetBSD: patch-src_connections.c,v 1.1 2016/10/17 22:00:22 nros Exp $
* NetBSD does not have accept4 but uses paccept.
--- src/connections.c.orig	2016-10-17 18:54:19.000000000 +0000
+++ src/connections.c
@@ -1027,7 +1027,11 @@ connection *connection_accept(server *sr
 	cnt_len = sizeof(cnt_addr);
 
 #if defined(SOCK_CLOEXEC) && defined(SOCK_NONBLOCK)
+#if defined(__NetBSD__)
+	cnt = paccept(srv_socket->fd, (struct sockaddr *) &cnt_addr, &cnt_len, NULL, SOCK_CLOEXEC | SOCK_NONBLOCK);
+#else
 	cnt = accept4(srv_socket->fd, (struct sockaddr *) &cnt_addr, &cnt_len, SOCK_CLOEXEC | SOCK_NONBLOCK);
+#endif
 #else
 	cnt = accept(srv_socket->fd, (struct sockaddr *) &cnt_addr, &cnt_len);
 #endif
