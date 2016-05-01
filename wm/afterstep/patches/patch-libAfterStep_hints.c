$NetBSD: patch-libAfterStep_hints.c,v 1.1 2016/05/01 19:26:35 dholland Exp $

Use ctype.h correctly.

--- libAfterStep/hints.c~	2009-12-31 17:40:57.000000000 +0000
+++ libAfterStep/hints.c
@@ -144,7 +144,7 @@ merge_command_line (ASHints * clean, ASS
 						{
 							register char *g = raw->wm_cmd_argv[i + 1];
 
-							if (isdigit ((int)*g) || ((*g == '-' || *g == '+') && isdigit ((int)*(g + 1))))
+							if (isdigit ((unsigned char)*g) || ((*g == '-' || *g == '+') && isdigit ((unsigned char)*(g + 1))))
 								if (mystrcasecmp (raw->wm_cmd_argv[i], "-g") == 0 ||
 									mystrcasecmp (raw->wm_cmd_argv[i], "-geometry") == 0)
 								{
@@ -168,7 +168,7 @@ merge_command_line (ASHints * clean, ASS
 						register int k ;
 						Bool add_quotes = False ;
 						for (k = 0; src[k]; k++)
-							if( isspace(src[k]) || 
+							if( isspace((unsigned char)src[k]) || 
 								src[k] == '#' ||
 								src[k] == '*' ||
 								src[k] == '$' ||
@@ -177,7 +177,7 @@ merge_command_line (ASHints * clean, ASS
 								src[k] == '<' ||
 								src[k] == '>' ||
 								src[k] == '|' ||
-								iscntrl(src[k])
+								iscntrl((unsigned char)src[k])
 								) 
 							{
 								add_quotes = True ;
@@ -2791,7 +2791,7 @@ get_client_icon_image( ScreenInfo * scr,
 					int i = 0;
 					char old ; 
 
-					while( name[i] && !isspace(name[i]) ) ++i ; 
+					while( name[i] && !isspace((unsigned char)name[i]) ) ++i ; 
 					if( i > 0 ) 
 					{
 						old = name[i];
