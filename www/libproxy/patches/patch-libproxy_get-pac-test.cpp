$NetBSD: patch-libproxy_get-pac-test.cpp,v 1.1 2017/06/08 11:27:06 adam Exp $

Fix a typo.

--- libproxy/test/get-pac-test.cpp.orig	2017-06-08 10:13:10.000000000 +0000
+++ libproxy/test/get-pac-test.cpp
@@ -130,7 +130,7 @@ class TestServer {
 
 #ifdef SO_NOSIGPIPE
 			int i = 1;
-			setsockopt(c_sock, SOL_SOCKET, SO_NOSIGPIPE, &i, sizeof(i));
+			setsockopt(csock, SOL_SOCKET, SO_NOSIGPIPE, &i, sizeof(i));
 #endif
 
 			// Read request
