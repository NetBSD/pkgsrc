$NetBSD: patch-server.c,v 1.1 2026/04/14 12:11:49 kikadf Exp $

* Fix prepare_socket() without SO_DOMAIN

--- server.c.orig	2026-02-06 08:28:05.607636888 +0000
+++ server.c
@@ -527,9 +527,27 @@ prepare_socket(int fd)
         return false;
     }
 
+#ifndef SO_DOMAIN
+    struct sockaddr_storage ss;
+    socklen_t l = sizeof(ss);
+    if (getsockname(fd, (struct sockaddr*)&ss, &l) == -1) {
+        LOG_ERRNO("getsockname failed on passed file descriptor");
+        return false;
+    }
+    if (ss.ss_family != AF_UNIX) {
+        LOG_ERR("wrong socket domain: expected AF_UNIX, got %d",
+                    ss.ss_family);
+        return false;
+    }
+
+    int const socket_options[] = { SO_ACCEPTCONN, SO_TYPE };
+    int const socket_options_values[] = { NON_ZERO_OPT, SOCK_STREAM};
+    char const * const socket_options_names[] = { "SO_ACCEPTCONN", "SO_TYPE" };
+#else
     int const socket_options[] = { SO_DOMAIN, SO_ACCEPTCONN, SO_TYPE };
     int const socket_options_values[] = { AF_UNIX, NON_ZERO_OPT, SOCK_STREAM};
     char const * const socket_options_names[] = { "SO_DOMAIN", "SO_ACCEPTCONN", "SO_TYPE" };
+#endif
 
     xassert(ALEN(socket_options) == ALEN(socket_options_values));
     xassert(ALEN(socket_options) == ALEN(socket_options_names));
