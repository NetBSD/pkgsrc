$NetBSD: patch-src_Server_Config.c,v 1.1 2016/04/03 20:24:27 joerg Exp $

--- src/Server/Config.c.orig	2016-04-03 16:01:12.152955846 +0000
+++ src/Server/Config.c
@@ -648,9 +648,6 @@ conf_parse_key(line,buf,key)
 	case K_ENC:
 		sscanf(buf,"%*s %s",b[0]);
 		if ( conf_check_args(b,1) ) return ERROR_PREVIOUS;
-		if (!strcmp(b[0],"ssl2"))
-			Svr.enc=ENC_SSL2;
-		else
 		if (!strcmp(b[0],"ssl3"))
 			Svr.enc=ENC_SSL3;
 		else
