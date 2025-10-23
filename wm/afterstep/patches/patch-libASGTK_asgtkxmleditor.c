$NetBSD: patch-libASGTK_asgtkxmleditor.c,v 1.1 2025/10/23 01:28:07 gutteridge Exp $

Use ctype.h correctly.

--- libASGTK/asgtkxmleditor.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libASGTK/asgtkxmleditor.c
@@ -248,7 +248,7 @@ static char *get_validated_text (ASGtkXM
 					 xb.state, xb.tags_count, xb.level, xb.tag_type);
 
 			if (xb.state >= 0) {
-				if (isspace (text[char_count]) ||
+				if (isspace ((unsigned char)text[char_count]) ||
 						text[char_count] == '<' ||
 						text[char_count] == '>' ||
 						text[char_count] == '=' || text[char_count] == '\"'
@@ -684,7 +684,7 @@ insert_tag_template_at_cursor (ASGtkXMLV
 	start_text = gtk_text_iter_get_text (&line_start, &start);
 	if (start_text) {
 		for (i = 0; start_text[i] != '\0'; ++i)
-			if (!isspace (start_text[i]))
+			if (!isspace ((unsigned char)start_text[i]))
 				break;
 		if (start_text[i] == '\0')
 			skip_leading_eol = True;
