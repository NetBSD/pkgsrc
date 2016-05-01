$NetBSD: patch-libAfterStep_parser__xml.c,v 1.1 2016/05/01 19:26:35 dholland Exp $

Use ctype.h correctly.

--- libAfterStep/parser_xml.c~	2006-07-18 17:36:36.000000000 +0000
+++ libAfterStep/parser_xml.c
@@ -186,7 +186,7 @@ statement2xml_elem (ConfigDef * config)
 		}else if (get_flags(pterm->flags, TF_INDEXED))
 		{
 			int i = 0 ; 
-			while( isdigit(ptr[i]) ) ++i;
+			while( isdigit((unsigned char)ptr[i]) ) ++i;
 			if( i > 0 ) 
 			{	
         		index = mystrndup(ptr, i);
