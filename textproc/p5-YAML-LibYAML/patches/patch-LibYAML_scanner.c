$NetBSD: patch-LibYAML_scanner.c,v 1.1.2.2 2014/04/14 17:17:02 tron Exp $

* CVE-2013-6393
  https://bitbucket.org/xi/libyaml/commits/1d73f004f49e6962cf936da98aecf0aec95c4c50
* CVE-2014-2525
  https://bitbucket.org/xi/libyaml/commits/bce8b60f0b9af69fa9fab3093d0a41ba243de048

--- LibYAML/scanner.c.orig	2013-03-12 17:58:04.000000000 +0000
+++ LibYAML/scanner.c
@@ -2574,7 +2574,7 @@ yaml_parser_scan_tag_uri(yaml_parser_t *
 
     /* Resize the string to include the head. */
 
-    while (string.end - string.start <= (int)length) {
+    while ((size_t)(string.end - string.start) <= length) {
         if (!yaml_string_extend(&string.start, &string.pointer, &string.end)) {
             parser->error = YAML_MEMORY_ERROR;
             goto error;
@@ -2619,6 +2619,9 @@ yaml_parser_scan_tag_uri(yaml_parser_t *
         /* Check if it is a URI-escape sequence. */
 
         if (CHECK(parser->buffer, '%')) {
+            if (!STRING_EXTEND(parser, string))
+                goto error;
+
             if (!yaml_parser_scan_uri_escapes(parser,
                         directive, start_mark, &string)) goto error;
         }
