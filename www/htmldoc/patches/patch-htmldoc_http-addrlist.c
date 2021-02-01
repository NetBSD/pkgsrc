$NetBSD: patch-htmldoc_http-addrlist.c,v 1.2 2021/02/01 09:33:12 fcambus Exp $

Portability fix, s6_addr32 is not a standard.

--- htmldoc/http-addrlist.c.orig	2021-02-01 09:20:13.146886279 +0000
+++ htmldoc/http-addrlist.c
@@ -866,7 +866,7 @@ httpAddrGetList(const char *hostname,	/*
 #  ifdef _WIN32
 	temp->addr.ipv6.sin6_addr.u.Byte[15]   = 1;
 #  else
-	temp->addr.ipv6.sin6_addr.s6_addr32[3] = htonl(1);
+	temp->addr.ipv6.sin6_addr.s6_addr[15] = 1;
 #  endif /* _WIN32 */
 
         if (!first)
