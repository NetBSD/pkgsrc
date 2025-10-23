$NetBSD: patch-src_tools_ASRun_main.c,v 1.1 2025/10/23 01:28:09 gutteridge Exp $

Use ctype.h correctly.

--- src/tools/ASRun/main.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ src/tools/ASRun/main.c
@@ -182,7 +182,7 @@ exec_command(char **ptext, ASRunTool too
 	}	 
 	if( text && tool == ASRTool_ASConfigFile ) 		
 	{
-		if( isalpha(text[0]) ) 
+		if( isalpha((unsigned char)text[0]) ) 
 		{
 			char *fullfilename = NULL ; 
 			char *fulldirname = NULL ; 
