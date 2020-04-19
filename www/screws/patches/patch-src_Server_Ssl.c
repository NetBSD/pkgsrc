$NetBSD: patch-src_Server_Ssl.c,v 1.2 2020/04/19 06:06:00 plunky Exp $

remove deprecatd methods

--- src/Server/Ssl.c.orig	2004-09-16 22:05:58.000000000 +0000
+++ src/Server/Ssl.c
@@ -82,12 +82,6 @@ SslInit(n,ctx)
 	
 	switch(Svr.enc)
 	{
-	case ENC_SSL2:
-		sm=SSLv2_server_method();
-		break;
-	case ENC_SSL3:
-		sm=SSLv3_server_method();
-		break;
 	case ENC_SSL23:
 		sm=SSLv23_server_method();
 		break;
