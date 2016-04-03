$NetBSD: patch-src_Server_Ssl.h,v 1.1 2016/04/03 20:24:27 joerg Exp $

--- src/Server/Ssl.h.orig	2016-04-03 16:01:03.871663755 +0000
+++ src/Server/Ssl.h
@@ -9,7 +9,6 @@
 #endif
 
 enum {
-	ENC_SSL2,
 	ENC_SSL3,
 	ENC_SSL23,
 	ENC_TLS
