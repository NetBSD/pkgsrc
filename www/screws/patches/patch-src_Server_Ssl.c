$NetBSD: patch-src_Server_Ssl.c,v 1.1 2016/04/03 20:24:27 joerg Exp $

--- src/Server/Ssl.c.orig	2016-04-03 16:00:51.049640130 +0000
+++ src/Server/Ssl.c
@@ -82,9 +82,6 @@ SslInit(n,ctx)
 	
 	switch(Svr.enc)
 	{
-	case ENC_SSL2:
-		sm=SSLv2_server_method();
-		break;
 	case ENC_SSL3:
 		sm=SSLv3_server_method();
 		break;
