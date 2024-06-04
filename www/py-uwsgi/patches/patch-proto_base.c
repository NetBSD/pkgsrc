$NetBSD: patch-proto_base.c,v 1.1 2024/06/04 11:50:46 joerg Exp $

Use same non-blocking handling on NetBSD as on Linux.

--- proto/base.c.orig	2024-06-03 12:06:13.035432857 +0000
+++ proto/base.c
@@ -97,7 +97,7 @@ uint16_t proto_base_add_uwsgi_var(struct
 int uwsgi_proto_base_accept(struct wsgi_request *wsgi_req, int fd) {
 
 	wsgi_req->c_len = sizeof(struct sockaddr_un);
-#if defined(__linux__) && defined(SOCK_NONBLOCK) && !defined(OBSOLETE_LINUX_KERNEL)
+#if (defined(__linux__)||defined(__NetBSD__)) && defined(SOCK_NONBLOCK) && !defined(OBSOLETE_LINUX_KERNEL)
 	return accept4(fd, (struct sockaddr *) &wsgi_req->client_addr, (socklen_t *) & wsgi_req->c_len, SOCK_NONBLOCK);
 #elif defined(__linux__)
 	int client_fd = accept(fd, (struct sockaddr *) &wsgi_req->client_addr, (socklen_t *) & wsgi_req->c_len);
