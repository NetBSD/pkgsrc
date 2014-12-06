$NetBSD: patch-rest_rest-xml-parser.c,v 1.1 2014/12/06 07:41:16 obache Exp $

xml-parser: Add missing break in switch statement
This would result in an inappropriate debug message appearing on valid
text data.

https://git.gnome.org/browse/librest/commit/?id=272db68e131a20652c98453b75b9c743cda2b327

--- rest/rest-xml-parser.c.orig	2014-09-02 19:23:50.000000000 +0000
+++ rest/rest-xml-parser.c
@@ -197,6 +197,7 @@ rest_xml_parser_parse_from_data (RestXml
         cur_node->content = g_strdup (G(xmlTextReaderConstValue (reader)));
         REST_DEBUG (XML_PARSER, "Text content found: %s",
                  cur_node->content);
+        break;
       default:
         REST_DEBUG (XML_PARSER, "Found unknown content with type: 0x%x", 
                  xmlTextReaderNodeType (reader));
