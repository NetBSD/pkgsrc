$NetBSD: patch-lib_connect.c,v 1.1 2012/07/20 08:22:04 marino Exp $

DragonFly uses millisecond as the unit of TCP_KEEP{IDLE} rather than second
Patch to be submitted upstream.

--- lib/connect.c.orig	2012-04-25 15:29:20.000000000 +0000
+++ lib/connect.c
@@ -105,6 +105,10 @@ tcpkeepalive(struct SessionHandle *data,
   else {
 #ifdef TCP_KEEPIDLE
     optval = curlx_sltosi(data->set.tcp_keepidle);
+#ifdef __DragonFly__
+    /* DragonFlyBSD uses millisecond as KEEPIDLE unit */
+    optval *= 1000;
+#endif
     if(setsockopt(sockfd, IPPROTO_TCP, TCP_KEEPIDLE,
           (void *)&optval, sizeof(optval)) < 0) {
       infof(data, "Failed to set TCP_KEEPIDLE on fd %d\n", sockfd);
@@ -112,6 +116,10 @@ tcpkeepalive(struct SessionHandle *data,
 #endif
 #ifdef TCP_KEEPINTVL
     optval = curlx_sltosi(data->set.tcp_keepintvl);
+#ifdef __DragonFly__
+    /* DragonFlyBSD uses millisecond as KEEPINTVL unit */
+    optval *= 1000;
+#endif
     if(setsockopt(sockfd, IPPROTO_TCP, TCP_KEEPINTVL,
           (void *)&optval, sizeof(optval)) < 0) {
       infof(data, "Failed to set TCP_KEEPINTVL on fd %d\n", sockfd);
