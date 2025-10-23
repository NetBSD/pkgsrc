$NetBSD: patch-src_afterstep_aswindow.c,v 1.1 2025/10/23 01:28:09 gutteridge Exp $

Use ctype.h correctly.

--- src/afterstep/aswindow.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ src/afterstep/aswindow.c
@@ -196,7 +196,7 @@ static void stripreplace_geometry_size (
 	if (geom) {
 
 		int i = 0;
-		if (isdigit (geom[0]))
+		if (isdigit ((unsigned char)geom[0]))
 			while (geom[++i])
 				if (geom[i] == '+' || geom[i] == '-')
 					break;
@@ -237,7 +237,7 @@ static char *make_application_name (ASWi
 	if (name) {
 		int i = 0;
 		while (name[i] != '\0') {		/* we do not want to have path in names as well */
-			if (!isalnum (name[i]) && !isspace (name[i]))
+			if (!isalnum ((unsigned char)name[i]) && !isspace ((unsigned char)name[i]))
 				break;
 			if (++i >= 80)
 				break;
@@ -739,7 +739,7 @@ ASWindow *complex_pattern2ASWindow (char
 				++matches_reqired;
 				ptr = parse_semicolon_token (ptr, tmp, &tmp_len);
 				LOCAL_DEBUG_OUT ("final pattern = \"%s\"", tmp);
-				if (tmp[0] == '#' && isdigit (tmp[1])) {
+				if (tmp[0] == '#' && isdigit ((unsigned char)tmp[1])) {
 					res_name_no = atoi (tmp + 1);
 					LOCAL_DEBUG_OUT ("res_name_no = %d", res_name_no);
 				} else if (tmp[0]) {
