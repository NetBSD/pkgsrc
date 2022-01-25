$NetBSD: patch-uwsgi.h,v 1.9 2022/01/25 10:30:51 wiz Exp $

Avoid using "sun" which breaks on SunOS

--- uwsgi.h.orig	2020-06-17 09:03:34.000000000 +0000
+++ uwsgi.h
@@ -1631,7 +1635,7 @@ struct wsgi_request {
 	union address {
 		struct sockaddr_in sin;
 		struct sockaddr_in6 sin6;
-		struct sockaddr_un sun;
+		struct sockaddr_un so_sun;
 	} client_addr;
 
 	uint8_t websocket_is_fin;
