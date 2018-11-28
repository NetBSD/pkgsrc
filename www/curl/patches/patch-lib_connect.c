$NetBSD: patch-lib_connect.c,v 1.3 2018/11/28 01:31:45 sevan Exp $

EBADIOCTL doesn't exist on more recent Minix.

--- lib/connect.c.orig	Mon Nov 19 14:23:45 2018
+++ lib/connect.c
@@ -522,7 +522,7 @@ static bool verifyconnect(curl_socket_t sockfd, int *e
     err = 0;
   }
 #endif
-#ifdef __minix
+#if defined EBADIOCTL && defined __minix
   /* Minix 3.1.x doesn't support getsockopt on UDP sockets */
   if(EBADIOCTL == err) {
     SET_SOCKERRNO(0);
