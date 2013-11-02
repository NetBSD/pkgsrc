$NetBSD: patch-enc.h,v 1.2 2013/11/02 07:32:28 obache Exp $

Respect IPv6 build option used throughout rest of x11vnc

--- x11vnc/enc.h.orig	2011-08-10 22:31:32.000000000 +0000
+++ x11vnc/enc.h
@@ -1733,7 +1733,7 @@ static void enc_connections(int listen_p
 	}
 
 	try6:
-#ifdef AF_INET6
+#if X11VNC_IPV6 && defined(AF_INET6)
 	if (!getenv("ULTRAVNC_DSM_HELPER_NOIPV6")) {
 		struct sockaddr_in6 sin;
 		int one = 1, sock = -1;
@@ -1826,7 +1826,7 @@ static void enc_connections(int listen_p
 			exit(1);
 		}
 	} else if (FD_ISSET(listen_fd6, &fds)) {
-#ifdef AF_INET6
+#if X11VNC_IPV6 && defined(AF_INET6)
 		struct sockaddr_in6 addr;
 		socklen_t addrlen = sizeof(addr);
 
