$NetBSD: patch-modules_filters_mod__xml2enc.c,v 1.2 2024/01/31 09:38:13 taca Exp $

* Fix build with libxml2-2.12.4 from revision #1914013.

--- modules/filters/mod_xml2enc.c.orig	2020-02-21 00:33:40.000000000 +0000
+++ modules/filters/mod_xml2enc.c
@@ -206,11 +206,11 @@ static void sniff_encoding(request_rec* 
             }
         }
     }
-  
+
     /* to sniff, first we look for BOM */
     if (ctx->xml2enc == XML_CHAR_ENCODING_NONE) {
-        ctx->xml2enc = xmlDetectCharEncoding((const xmlChar*)ctx->buf,
-                                             ctx->bytes); 
+        ctx->xml2enc = xmlDetectCharEncoding((const unsigned char*)ctx->buf,
+                                             ctx->bytes);
         if (HAVE_ENCODING(ctx->xml2enc)) {
             ap_log_rerror(APLOG_MARK, APLOG_INFO, 0, r, APLOGNO(01432)
                           "Got charset from XML rules.") ;
