$NetBSD: patch-libAfterConf_Color.c,v 1.2 2021/07/11 12:13:17 bsiegert Exp $

Use ctype.h correctly.
Fix some printf formats.

--- libAfterConf/Color.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterConf/Color.c
@@ -339,7 +339,7 @@ translate_gtkrc_template_file (const cha
 		while (fgets (&buffer[0], MAXLINELENGTH, src_fp)) {
 			int i = 0;
 
-			while (isspace (buffer[i]))
+			while (isspace ((unsigned char)buffer[i]))
 				++i;
 			if (buffer[i] != '\n' && buffer[i] != '#' && buffer[i] != '\0'
 					&& buffer[i] != '\r') {
@@ -357,7 +357,7 @@ translate_gtkrc_template_file (const cha
 					if (buffer[i] == '\"') {
 						char *token = &buffer[i + 1];
 
-						if (isalpha (token[0])) {
+						if (isalpha ((unsigned char)token[0])) {
 							int len = 0;
 
 							while (token[len] != '\0' && token[len] != '\"')
