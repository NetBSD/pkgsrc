$NetBSD: patch-libAfterBase_xml.h,v 1.1 2025/10/23 01:28:08 gutteridge Exp $

Use ctype.h correctly.

--- libAfterBase/xml.h.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterBase/xml.h
@@ -7,7 +7,7 @@ extern "C" {
 
 struct ASHashTable;
 
-#define xml_tagchar(a) (isalnum(a) || (a) == '-' || (a) == '_')
+#define xml_tagchar(a) (isalnum((unsigned char)a) || (a) == '-' || (a) == '_')
 
 #define XML_CDATA_STR 		"CDATA"
 #define XML_CONTAINER_STR	"CONTAINER"
