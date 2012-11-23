$NetBSD: patch-lib_modxslt-libxml.c,v 1.1 2012/11/23 11:38:15 joerg Exp $

--- lib/modxslt-libxml.c.orig	2012-11-22 21:06:39.000000000 +0000
+++ lib/modxslt-libxml.c
@@ -537,9 +537,9 @@ xmlDocPtr mxslt_doc_xml_parse(mxslt_doc_
   }
 
   input->buf=buf;
-  input->base=input->buf->buffer->content;
-  input->cur=input->buf->buffer->content;
-  input->end=&input->buf->buffer->content[input->buf->buffer->use];
+  input->base=xmlBufferContent(input->buf->buffer);
+  input->cur=xmlBufferContent(input->buf->buffer);
+  input->end=xmlBufferContent(input->buf->buffer) + xmlBufferLength(input->buf->buffer);
 
   inputPush(ctx, input);
 
