$NetBSD: patch-src_extensions_ocsipersist-pgsql_ocsipersist.ml,v 1.1 2018/11/29 10:54:14 jaapb Exp $

Replace tyxml.parser with xml-light (patch from upstream)
--- src/extensions/ocsipersist-pgsql/ocsipersist.ml.orig	2018-02-01 12:55:17.000000000 +0000
+++ src/extensions/ocsipersist-pgsql/ocsipersist.ml
@@ -275,11 +275,9 @@ let fold_table = fold_step
 
 let iter_block a b = failwith "Ocsipersist.iter_block: not implemented"
 
-
-open Simplexmlparser
 let parse_global_config = function
   | [] -> ()
-  | [Element ("database", attrs, [])] -> let parse_attr = function
+  | [Xml.Element ("database", attrs, [])] -> let parse_attr = function
     | ("host", h) -> host := Some h
     | ("port", p) -> begin
         try port := Some (int_of_string p)
