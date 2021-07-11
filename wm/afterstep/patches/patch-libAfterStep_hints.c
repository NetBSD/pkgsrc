$NetBSD: patch-libAfterStep_hints.c,v 1.2 2021/07/11 12:13:17 bsiegert Exp $

Use ctype.h correctly.

--- libAfterStep/hints.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterStep/hints.c
@@ -150,8 +150,8 @@ merge_command_line (ASHints * clean, ASS
 						if (raw->wm_cmd_argv[i + 1] != NULL) {
 							register char *g = raw->wm_cmd_argv[i + 1];
 
-							if (isdigit ((int)*g)
-									|| ((*g == '-' || *g == '+') && isdigit ((int)*(g + 1))))
+							if (isdigit ((unsigned char)*g)
+									|| ((*g == '-' || *g == '+') && isdigit ((unsigned char)*(g + 1))))
 								if (mystrcasecmp (raw->wm_cmd_argv[i], "-g") == 0
 										|| mystrcasecmp (raw->wm_cmd_argv[i],
 																		 "-geometry") == 0) {
@@ -175,13 +175,13 @@ merge_command_line (ASHints * clean, ASS
 						Bool add_quotes = False;
 
 						for (k = 0; src[k]; k++)
-							if (isspace (src[k]) ||
+							if (isspace ((unsigned char)src[k]) ||
 									src[k] == '#' ||
 									src[k] == '*' ||
 									src[k] == '$' ||
 									src[k] == ';' ||
 									src[k] == '&' || src[k] == '<' || src[k] == '>'
-									|| src[k] == '|' || iscntrl (src[k])) {
+									|| src[k] == '|' || iscntrl ((unsigned char)src[k])) {
 								add_quotes = True;
 								break;
 							}
@@ -2813,7 +2813,7 @@ ASImage *get_client_icon_image (ScreenIn
 					int i = 0;
 					char old;
 
-					while (name[i] && !isspace (name[i]))
+					while (name[i] && !isspace ((unsigned char)name[i]))
 						++i;
 					if (i > 0) {
 						old = name[i];
