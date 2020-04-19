$NetBSD: patch-src_Server_Config.c,v 1.2 2020/04/19 06:06:00 plunky Exp $

remove deprecated methods

--- src/Server/Config.c.orig	2004-09-16 22:05:58.000000000 +0000
+++ src/Server/Config.c
@@ -648,12 +648,6 @@ conf_parse_key(line,buf,key)
 	case K_ENC:
 		sscanf(buf,"%*s %s",b[0]);
 		if ( conf_check_args(b,1) ) return ERROR_PREVIOUS;
-		if (!strcmp(b[0],"ssl2"))
-			Svr.enc=ENC_SSL2;
-		else
-		if (!strcmp(b[0],"ssl3"))
-			Svr.enc=ENC_SSL3;
-		else
 		if (!strcmp(b[0],"ssl23"))
 			Svr.enc=ENC_SSL23;
 		else
