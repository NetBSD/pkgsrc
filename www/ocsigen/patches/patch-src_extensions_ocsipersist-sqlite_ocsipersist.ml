$NetBSD: patch-src_extensions_ocsipersist-sqlite_ocsipersist.ml,v 1.1 2018/11/29 10:54:14 jaapb Exp $

Replace tyxml.parser with xml-light (patch from upstream)
--- src/extensions/ocsipersist-sqlite/ocsipersist.ml.orig	2018-02-01 12:55:17.000000000 +0000
+++ src/extensions/ocsipersist-sqlite/ocsipersist.ml
@@ -36,11 +36,10 @@ exception Ocsipersist_error
 
 (*****************************************************************************)
 
-open Simplexmlparser
 (** getting the directory from config file *)
 let rec parse_global_config = function
   | [] -> None
-  | (Element ("database", [("file", s)], []))::[] -> Some s
+  | (Xml.Element ("database", [("file", s)], []))::[] -> Some s
   | _ -> raise (Ocsigen_extensions.Error_in_config_file
                   ("Unexpected content inside Ocsipersist config"))
 
