$NetBSD: patch-uwsgi.h,v 1.11 2023/08/01 12:33:17 adam Exp $

Avoid using "sun" which breaks on SunOS
https://github.com/unbit/uwsgi/pull/2506

--- uwsgi.h.orig	2023-07-27 15:34:12.000000000 +0000
+++ uwsgi.h
@@ -1634,7 +1634,7 @@ struct wsgi_request {
 	union address {
 		struct sockaddr_in sin;
 		struct sockaddr_in6 sin6;
-		struct sockaddr_un sun;
+		struct sockaddr_un so_sun;
 	} client_addr;
 
 	uint8_t websocket_is_fin;
