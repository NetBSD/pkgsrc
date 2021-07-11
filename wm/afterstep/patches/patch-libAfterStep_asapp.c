$NetBSD: patch-libAfterStep_asapp.c,v 1.2 2021/07/11 12:13:17 bsiegert Exp $

Use ctype.h correctly.

--- libAfterStep/asapp.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterStep/asapp.c
@@ -1431,7 +1431,7 @@ spawn_child (const char *cmd, int single
 			while (display[i])
 				++i;
 
-			while (i > 0 && isdigit (display[--i])) ;
+			while (i > 0 && isdigit ((unsigned char)display[--i])) ;
 			if (display[i] == '.')
 				display[i + 1] = '\0';
 /*
@@ -1518,7 +1518,7 @@ spawn_child (const char *cmd, int single
 					 len, cmdl, (int)strlen (cmdl), as_app_args.locale,
 					 (int)(ptr - cmdl));
 			if (as_app_args.locale && as_app_args.locale[0]
-					&& !isspace (as_app_args.locale[0]))
+					&& !isspace ((unsigned char)as_app_args.locale[0]))
 				ptr += sprintf (ptr, " -L %s", as_app_args.locale);
 
 #ifdef DEBUG_TRACE_X
@@ -1546,7 +1546,7 @@ spawn_child (const char *cmd, int single
 			int i = ptr - cmdl;
 
 			while (--i >= 0)
-				if (!isspace (cmdl[i]))
+				if (!isspace ((unsigned char)cmdl[i]))
 					break;
 			do_fork = (i < 0 || cmdl[i] != '&');
 		}
