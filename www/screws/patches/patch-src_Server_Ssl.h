$NetBSD: patch-src_Server_Ssl.h,v 1.2 2020/04/19 06:06:00 plunky Exp $

remove deprecated methods

--- src/Server/Ssl.h.orig	2004-09-16 22:05:58.000000000 +0000
+++ src/Server/Ssl.h
@@ -9,8 +9,6 @@
 #endif
 
 enum {
-	ENC_SSL2,
-	ENC_SSL3,
 	ENC_SSL23,
 	ENC_TLS
 };
