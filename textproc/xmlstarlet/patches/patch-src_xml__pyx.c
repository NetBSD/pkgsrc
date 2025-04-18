$NetBSD: patch-src_xml__pyx.c,v 1.1 2025/04/18 06:15:32 wiz Exp $

libxml2 defines ATTRIBUTE_UNUSED.

--- src/xml_pyx.c.orig	2025-04-18 06:14:09.644457134 +0000
+++ src/xml_pyx.c
@@ -200,7 +200,7 @@ pyxExternalEntityReferenceHandler(void* 
 }
 
 static void
-pyxExternalSubsetHandler(void *ctx ATTRIBUTE_UNUSED, const xmlChar *name,
+pyxExternalSubsetHandler(void *ctx XS_ATTRIBUTE_UNUSED, const xmlChar *name,
                          const xmlChar *ExternalID, const xmlChar *SystemID)
 {
     fprintf(stdout, "D %s PUBLIC", name); /* TODO: re-check */
@@ -215,7 +215,7 @@ pyxExternalSubsetHandler(void *ctx ATTRI
 }
 
 static void
-pyxCommentHandler(void *ctx ATTRIBUTE_UNUSED, const xmlChar *value)
+pyxCommentHandler(void *ctx XS_ATTRIBUTE_UNUSED, const xmlChar *value)
 {
     fprintf(stdout,"C");
     SanitizeData(value, xmlStrlen(value));
@@ -223,7 +223,7 @@ pyxCommentHandler(void *ctx ATTRIBUTE_UN
 }
 
 static void
-pyxCdataBlockHandler(void *ctx ATTRIBUTE_UNUSED, const xmlChar *value, int len)
+pyxCdataBlockHandler(void *ctx XS_ATTRIBUTE_UNUSED, const xmlChar *value, int len)
 {
     fprintf(stdout,"[");
     SanitizeData(value, len);
