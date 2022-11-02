$NetBSD: patch-uwsgi.h,v 1.10 2022/11/02 07:26:47 wiz Exp $

Avoid using "sun" which breaks on SunOS
https://github.com/unbit/uwsgi/pull/2506

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
