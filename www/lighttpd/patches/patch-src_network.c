$NetBSD: patch-src_network.c,v 1.1 2017/10/29 00:34:30 schmonz Exp $

Fix build without IPv6 (from https://redmine.lighttpd.net/issues/2832).

--- src/network.c.orig	2017-10-22 20:09:57.000000000 +0000
+++ src/network.c
@@ -77,9 +77,13 @@ static void network_host_normalize_addr_
     if (addr->plain.sa_family == AF_INET6)
         buffer_append_string_len(host, CONST_STR_LEN("]"));
     if (addr->plain.sa_family != AF_UNIX) {
+      #ifdef HAVE_IPV6
         unsigned short port = (addr->plain.sa_family == AF_INET)
           ? ntohs(addr->ipv4.sin_port)
           : ntohs(addr->ipv6.sin6_port);
+      #else
+        unsigned short port = ntohs(addr->ipv4.sin_port);
+      #endif
         buffer_append_string_len(host, CONST_STR_LEN(":"));
         buffer_append_int(host, (int)port);
     }
