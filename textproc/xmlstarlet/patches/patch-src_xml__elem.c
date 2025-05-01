$NetBSD: patch-src_xml__elem.c,v 1.1 2025/05/01 15:16:21 tnn Exp $

* sprinkle some const to appease clang and libxml2

--- src/xml_elem.c.orig	2025-05-01 14:44:26.773438402 +0000
+++ src/xml_elem.c
@@ -178,7 +178,7 @@ elInitOptions(elOptions *ops)
 }
 
 typedef struct {
-    xmlChar **array;
+    const xmlChar **array;
     int offset;
 } ArrayDest;
 
@@ -186,7 +186,7 @@ typedef struct {
  * put @name into @data->array[@data->offset]
  */
 static void
-hash_key_put(void *payload, void *data, xmlChar *name)
+hash_key_put(void *payload, void *data, const xmlChar *name)
 {
     ArrayDest *dest = data;
     dest->array[dest->offset++] = name;
