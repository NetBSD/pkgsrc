$NetBSD: patch-src_extensions_ocsipersist-dbm_ocsipersist.ml,v 1.1 2018/11/29 10:54:14 jaapb Exp $

Replace tyxml.parser with xml-light (patch from upstream)
--- src/extensions/ocsipersist-dbm/ocsipersist.ml.orig	2018-02-01 12:55:17.000000000 +0000
+++ src/extensions/ocsipersist-dbm/ocsipersist.ml
@@ -38,26 +38,25 @@ let socketname = "socket"
 (*****************************************************************************)
 (** Internal functions: storage directory *)
 
-open Simplexmlparser
 (** getting the directory from config file *)
 let rec parse_global_config (store, ocsidbm, delayloading as d) = function
   | [] -> d
-  | Element ("delayloading", [("val", ("true" | "1"))], []) :: ll ->
+  | Xml.Element ("delayloading", [("val", ("true" | "1"))], []) :: ll ->
     parse_global_config (store, ocsidbm, true) ll
 
-  | Element ("store", [("dir", s)], []) :: ll ->
+  | Xml.Element ("store", [("dir", s)], []) :: ll ->
     if store = None then
       parse_global_config ((Some s), ocsidbm, delayloading) ll
     else
       Ocsigen_extensions.badconfig "Ocsipersist: Duplicate <store> tag"
 
-  | Element ("ocsidbm", [("name", s)], []) :: ll ->
+  | Xml.Element ("ocsidbm", [("name", s)], []) :: ll ->
     if ocsidbm = None then
       parse_global_config (store, (Some s), delayloading) ll
     else
       Ocsigen_extensions.badconfig "Ocsipersist: Duplicate <ocsidbm> tag"
 
-  | (Element (s,_,_))::ll -> Ocsigen_extensions.badconfig "Bad tag %s" s
+  | (Xml.Element (s,_,_))::ll -> Ocsigen_extensions.badconfig "Bad tag %s" s
 
   | _ -> Ocsigen_extensions.badconfig
            "Unexpected content inside Ocsipersist config"
