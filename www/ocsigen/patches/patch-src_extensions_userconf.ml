$NetBSD: patch-src_extensions_userconf.ml,v 1.1 2018/11/29 10:54:14 jaapb Exp $

Replace tyxml.parser with xml-light (patch from upstream)
--- src/extensions/userconf.ml.orig	2018-02-01 12:55:17.000000000 +0000
+++ src/extensions/userconf.ml
@@ -98,11 +98,15 @@ let subresult new_req user_parse_site co
 
 
 let conf_to_xml conf =
-  try Simplexmlparser.xmlparser_file conf
+  try [Xml.parse_file conf]
   with
   | Sys_error _ -> raise NoConfFile
-  | Simplexmlparser.Xml_parser_error s ->
-    raise (Ocsigen_extensions.Error_in_config_file s)
+  | Xml.Error (s, loc) ->
+    let begin_char, end_char = Xml.range loc and line = Xml.line loc in
+    raise (Ocsigen_extensions.Error_in_config_file
+             (Printf.sprintf "%s, line %d, characters %d-%d"
+                (Xml.error_msg s)
+                line begin_char end_char))
 
 
 let gen hostpattern sitepath (regexp, conf, url, prefix, localpath) = function
