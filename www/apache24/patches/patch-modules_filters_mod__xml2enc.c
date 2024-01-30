$NetBSD: patch-modules_filters_mod__xml2enc.c,v 1.1 2024/01/30 14:41:29 taca Exp $

* Fix build with libxml2-2.12.4.

--- modules/filters/mod_xml2enc.c.orig	2020-02-21 00:33:40.000000000 +0000
+++ modules/filters/mod_xml2enc.c
@@ -35,6 +35,7 @@
 #endif
 
 /* libxml2 */
+#include <libxml/xmlstring.h>
 #include <libxml/encoding.h>
 
 #if defined(__clang__)
