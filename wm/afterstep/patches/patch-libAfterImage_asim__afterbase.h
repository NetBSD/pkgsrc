$NetBSD: patch-libAfterImage_asim__afterbase.h,v 1.1 2025/10/23 01:28:08 gutteridge Exp $

Use ctype.h correctly.

--- libAfterImage/asim_afterbase.h.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterImage/asim_afterbase.h
@@ -407,7 +407,7 @@ void asim_wait_tick ();
 /* TODO : add xml stuff */
 /* from xml.c  */
 
-#define xml_tagchar(a) (isalnum(a) || (a) == '-' || (a) == '_')
+#define xml_tagchar(a) (isalnum((unsigned char)a) || (a) == '-' || (a) == '_')
 
 #define XML_CDATA_STR 		"CDATA"
 #define XML_CONTAINER_STR	"CONTAINER"
