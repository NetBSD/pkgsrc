$NetBSD: patch-htmldoc_http-addrlist.c,v 1.1 2019/10/18 11:02:13 micha Exp $

Portability fix, s6_addr32 is not a standard.

--- htmldoc/http-addrlist.c.orig	2019-10-08 18:56:34.000000000 +0000
+++ htmldoc/http-addrlist.c
@@ -804,7 +804,7 @@ httpAddrGetList(const char *hostname,	/*
 #  ifdef WIN32
 	temp->addr.ipv6.sin6_addr.u.Byte[15]   = 1;
 #  else
-	temp->addr.ipv6.sin6_addr.s6_addr32[3] = htonl(1);
+	temp->addr.ipv6.sin6_addr.s6_addr[15] = 1;
 #  endif /* WIN32 */
 
         if (!first)
