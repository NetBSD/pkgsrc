$NetBSD: patch-src_extensions_extensiontemplate.ml,v 1.1 2018/11/29 10:54:14 jaapb Exp $

Replace tyxml.parser with xml-light (patch from upstream)
--- src/extensions/extensiontemplate.ml.orig	2018-02-01 12:55:17.000000000 +0000
+++ src/extensions/extensiontemplate.ml
@@ -41,7 +41,6 @@
 
 open Lwt
 open Ocsigen_extensions
-open Simplexmlparser
 
 
 
@@ -58,7 +57,7 @@ open Simplexmlparser
 
 let rec parse_global_config = function
   | [] -> ()
-  | (Element ("myoption", [("myattr", s)], []))::ll -> ()
+  | (Xml.Element ("myoption", [("myattr", s)], []))::ll -> ()
   | _ -> raise (Error_in_config_file
                   ("Unexpected content inside extensiontemplate config"))
 
@@ -126,8 +125,8 @@ let gen = function
 *)
 
 let parse_config path _ parse_site = function
-  | Element ("extensiontemplate", atts, []) -> gen
-  | Element (t, _, _) -> raise (Bad_config_tag_for_extension t)
+  | Xml.Element ("extensiontemplate", atts, []) -> gen
+  | Xml.Element (t, _, _) -> raise (Bad_config_tag_for_extension t)
   | _ ->
     raise (Error_in_config_file "Unexpected data in config file")
 
@@ -173,7 +172,7 @@ let exn_handler = raise
      {- raise [Bad_config_tag_for_extension] if it does not recognize that tag}
      {- return something of type [extension] (filter or page generator)}}
 *)
-let site_creator 
+let site_creator
     (hostpattern : Ocsigen_extensions.virtual_hosts)
     (config_info : Ocsigen_extensions.config_info)
   = parse_config
