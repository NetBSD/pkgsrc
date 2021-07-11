$NetBSD: patch-libAfterStep_parser__xml.c,v 1.2 2021/07/11 12:13:17 bsiegert Exp $

Use ctype.h correctly.

--- libAfterStep/parser_xml.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterStep/parser_xml.c
@@ -183,7 +183,7 @@ void statement2xml_elem (ConfigDef * con
 		} else if (get_flags (pterm->flags, TF_INDEXED)) {
 			int i = 0;
 
-			while (isdigit (ptr[i]))
+			while (isdigit ((unsigned char)ptr[i]))
 				++i;
 			if (i > 0) {
 				index = mystrndup (ptr, i);
