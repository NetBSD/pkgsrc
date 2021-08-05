$NetBSD: patch-uwsgi.h,v 1.8 2021/08/05 13:22:30 adam Exp $

Avoid clash with sys/user.h inclusion in logging.c on DragonFly BSD.
Avoid using "sun" which breaks on SunOS

--- uwsgi.h.orig	2020-06-17 09:03:34.000000000 +0000
+++ uwsgi.h
@@ -322,6 +322,10 @@ extern int pivot_root(const char *new_ro
 #elif defined(__CYGWIN__)
 #elif defined(__HURD__)
 #else
+#if defined(__DragonFly__)
+/* avoid clash with sys/user.h inclusion in logging.c */
+#define _KERNEL_STRUCTURES
+#endif /* __DragonFly__ */
 #include <sys/event.h>
 #endif
 
@@ -1631,7 +1635,7 @@ struct wsgi_request {
 	union address {
 		struct sockaddr_in sin;
 		struct sockaddr_in6 sin6;
-		struct sockaddr_un sun;
+		struct sockaddr_un so_sun;
 	} client_addr;
 
 	uint8_t websocket_is_fin;
