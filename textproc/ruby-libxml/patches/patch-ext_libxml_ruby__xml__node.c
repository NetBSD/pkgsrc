$NetBSD: patch-ext_libxml_ruby__xml__node.c,v 1.1 2012/09/27 13:09:11 taca Exp $

Adopt to libxml 2.9.0.

--- ext/libxml/ruby_xml_node.c.orig	2012-09-27 09:39:32.000000000 +0000
+++ ext/libxml/ruby_xml_node.c
@@ -619,9 +619,9 @@ static VALUE rxml_node_to_s(int argc, VA
   xmlOutputBufferFlush(output);
 
   if (output->conv)
-    result = rxml_new_cstr((const char*) output->conv->content, xencoding);
+    result = rxml_new_cstr((const char*) xmlBufContent(output->conv), xencoding);
   else
-    result = rxml_new_cstr((const char*) output->buffer->content, xencoding);
+    result = rxml_new_cstr((const char*) xmlBufContent(output->buffer), xencoding);
 
   xmlOutputBufferClose(output);
   
