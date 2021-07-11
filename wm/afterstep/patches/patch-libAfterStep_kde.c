$NetBSD: patch-libAfterStep_kde.c,v 1.2 2021/07/11 12:13:17 bsiegert Exp $

Use ctype.h correctly.

--- libAfterStep/kde.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterStep/kde.c
@@ -111,14 +111,14 @@ xml_elem_t *load_KDE_config (const char 
 			xml_elem_t *tag;
 			int i = 0;
 
-			while (isspace (buffer[i]))
+			while (isspace ((unsigned char)buffer[i]))
 				++i;
 			if (buffer[i] == '#') {
 				++i;
 				if ((tag = make_kde_config_comment_tag ()) != NULL) {
 					int len = strlen (&buffer[i]);
 
-					while (len > 0 && isspace (buffer[i + len - 1]))
+					while (len > 0 && isspace ((unsigned char)buffer[i + len - 1]))
 						--len;
 					if (len > 0) {
 						tag->child = create_CDATA_tag ();
