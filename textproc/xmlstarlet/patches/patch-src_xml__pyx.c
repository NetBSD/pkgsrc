$NetBSD: patch-src_xml__pyx.c,v 1.3 2025/04/18 15:39:44 wiz Exp $

Symbol was removed from libxml2 2.14.

--- src/xml_pyx.c.orig	2013-07-01 02:58:36.000000000 +0000
+++ src/xml_pyx.c
@@ -200,7 +200,7 @@ pyxExternalEntityReferenceHandler(void* 
 }
 
 static void
-pyxExternalSubsetHandler(void *ctx ATTRIBUTE_UNUSED, const xmlChar *name,
+pyxExternalSubsetHandler(void *ctx, const xmlChar *name,
                          const xmlChar *ExternalID, const xmlChar *SystemID)
 {
     fprintf(stdout, "D %s PUBLIC", name); /* TODO: re-check */
@@ -215,7 +215,7 @@ pyxExternalSubsetHandler(void *ctx ATTRI
 }
 
 static void
-pyxCommentHandler(void *ctx ATTRIBUTE_UNUSED, const xmlChar *value)
+pyxCommentHandler(void *ctx, const xmlChar *value)
 {
     fprintf(stdout,"C");
     SanitizeData(value, xmlStrlen(value));
@@ -223,7 +223,7 @@ pyxCommentHandler(void *ctx ATTRIBUTE_UN
 }
 
 static void
-pyxCdataBlockHandler(void *ctx ATTRIBUTE_UNUSED, const xmlChar *value, int len)
+pyxCdataBlockHandler(void *ctx, const xmlChar *value, int len)
 {
     fprintf(stdout,"[");
     SanitizeData(value, len);
