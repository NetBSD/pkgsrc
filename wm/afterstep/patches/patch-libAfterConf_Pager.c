$NetBSD: patch-libAfterConf_Pager.c,v 1.1 2025/10/23 01:28:08 gutteridge Exp $

Use ctype.h correctly.

--- libAfterConf/Pager.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterConf/Pager.c
@@ -453,7 +453,7 @@ PagerConfig *ParsePagerOptions (const ch
 							parse_filename (item.data.string,
 															&(config->shade_button[0]));
 
-					while (isspace (*tmp))
+					while (isspace ((unsigned char)*tmp))
 						++tmp;
 					if (*tmp != '\0')
 						parse_filename (tmp, &(config->shade_button[1]));
