$NetBSD: patch-src_os_unix_ngx__udp__sendmsg__chain.c,v 1.2 2018/04/12 06:49:39 adam Exp $

Fix building on NetBSD.

--- src/os/unix/ngx_udp_sendmsg_chain.c.orig	2017-06-16 13:11:29.459922906 +0000
+++ src/os/unix/ngx_udp_sendmsg_chain.c
@@ -271,7 +271,9 @@ ngx_sendmsg(ngx_connection_t *c, ngx_iov
 
             pkt = (struct in_pktinfo *) CMSG_DATA(cmsg);
             ngx_memzero(pkt, sizeof(struct in_pktinfo));
+#ifndef __NetBSD__
             pkt->ipi_spec_dst = sin->sin_addr;
+#endif
         }
 
 #endif
