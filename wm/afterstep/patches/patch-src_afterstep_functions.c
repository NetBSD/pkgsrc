$NetBSD: patch-src_afterstep_functions.c,v 1.1 2025/10/23 01:28:09 gutteridge Exp $

Use ctype.h correctly.

--- src/afterstep/functions.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ src/afterstep/functions.c
@@ -1292,7 +1292,7 @@ char *parse_term_cmdl (const char *term_
 	strcpy (full_cmdl, term_command);
 
 	while (curr_cmdl < cmdl_len) {
-		while (isspace (cmdl[curr_cmdl]))
+		while (isspace ((unsigned char)cmdl[curr_cmdl]))
 			++curr_cmdl;
 		if (mystrncasecmp (&(cmdl[curr_cmdl]), "if(", 3) == 0) {
 			int tmp;
@@ -1300,19 +1300,19 @@ char *parse_term_cmdl (const char *term_
 			curr_cmdl += 3;
 			tmp = curr_cmdl;
 			curr_cmdl += find_escaped_chr_pos (&(cmdl[curr_cmdl]), '}') + 1;
-			while (isspace (cmdl[tmp]))
+			while (isspace ((unsigned char)cmdl[tmp]))
 				++tmp;
 			if (mystrncasecmp (&(cmdl[tmp]), term_name, term_name_len) == 0) {
 				tmp += term_name_len;
-				while (isspace (cmdl[tmp]))
+				while (isspace ((unsigned char)cmdl[tmp]))
 					++tmp;
 				if (cmdl[tmp] == ')') {
 					++tmp;
-					while (isspace (cmdl[tmp]))
+					while (isspace ((unsigned char)cmdl[tmp]))
 						++tmp;
 					if (cmdl[tmp] == '{')
 						++tmp;
-					while (isspace (cmdl[tmp]))
+					while (isspace ((unsigned char)cmdl[tmp]))
 						++tmp;
 					full_cmdl[curr_full++] = ' ';
 					while (tmp < curr_cmdl - 1)
@@ -1338,7 +1338,7 @@ char *parse_term_cmdl (const char *term_
 			}
 
 			full_cmdl[curr_full++] = ' ';
-			while (curr_cmdl < cmdl_len && !isspace (cmdl[curr_cmdl]))
+			while (curr_cmdl < cmdl_len && !isspace ((unsigned char)cmdl[curr_cmdl]))
 				full_cmdl[curr_full++] = cmdl[curr_cmdl++];
 		}
 
