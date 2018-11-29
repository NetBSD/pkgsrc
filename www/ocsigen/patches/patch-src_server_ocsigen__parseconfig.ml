$NetBSD: patch-src_server_ocsigen__parseconfig.ml,v 1.1 2018/11/29 10:54:14 jaapb Exp $

Replace tyxml.parser with xml-light (patch from upstream)
--- src/server/ocsigen_parseconfig.ml.orig	2018-02-01 12:55:17.000000000 +0000
+++ src/server/ocsigen_parseconfig.ml
@@ -24,7 +24,7 @@
 open Ocsigen_lib
 open Ocsigen_socket
 
-open Simplexmlparser
+open Xml
 open Ocsigen_config
 
 let section = Lwt_log.Section.make "ocsigen:config"
@@ -184,10 +184,7 @@ let parse_string_tag tag s =
 
 
 let rec parser_config =
-  let rec verify_empty = function
-    | [] -> ()
-    | _ -> raise (Config_file_error "Don't know what to do with trailing data")
-  in let rec parse_servers n = function
+  let rec parse_servers n = function
     | [] -> (match n with
         | [] -> raise (Config_file_error ("<server> tag expected"))
         | _ -> n)
@@ -203,14 +200,13 @@ let rec parser_config =
         (* nouveau at the end *)
     | _ -> raise (Config_file_error ("syntax error inside <ocsigen>"))
   in function
-    | (Element ("ocsigen", [], l))::ll ->
-      verify_empty ll;
+    | (Element ("ocsigen", [], l)) ->
       parse_servers [] l
     | _ -> raise (Config_file_error "<ocsigen> tag expected")
 
 
 let parse_ext file =
-  parser_config (Simplexmlparser.xmlparser_file file)
+  parser_config (Xml.parse_file file)
 
 
 let preloadfile config () = Ocsigen_extensions.set_config config
@@ -785,6 +781,6 @@ let parse_config ?file () =
     | None -> Ocsigen_config.get_config_file ()
     | Some f -> f
   in
-  parser_config (Simplexmlparser.xmlparser_file file)
+  parser_config (Xml.parse_file file)
 
 (******************************************************************)
