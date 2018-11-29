$NetBSD: patch-src_extensions_deflatemod.ml,v 1.1 2018/11/29 10:54:14 jaapb Exp $

Replace tyxml.parser with xml-light (patch from upstream)
--- src/extensions/deflatemod.ml.orig	2018-02-01 12:55:17.000000000 +0000
+++ src/extensions/deflatemod.ml
@@ -26,7 +26,6 @@
 open Ocsigen_lib
 open Lwt
 open Ocsigen_extensions
-open Simplexmlparser
 open Ocsigen_headers
 
 let section = Lwt_log.Section.make "ocsigen:ext:deflate"
@@ -303,13 +302,13 @@ let filter choice_list = function
 
 let rec parse_global_config = function
   | [] -> ()
-  | (Element ("compress", [("level", l)], []))::ll ->
+  | (Xml.Element ("compress", [("level", l)], []))::ll ->
     let l = try int_of_string l
       with Failure _ -> raise (Error_in_config_file
                                  "Compress level should be an integer between 0 and 9") in
     compress_level := if (l <= 9 && l >= 0) then l else 6 ;
     parse_global_config ll
-  | (Element ("buffer", [("size", s)], []))::ll ->
+  | (Xml.Element ("buffer", [("size", s)], []))::ll ->
     let s = (try int_of_string s
              with Failure _ -> raise (Error_in_config_file
                                         "Buffer size should be a positive integer")) in
@@ -317,7 +316,7 @@ let rec parse_global_config = function
     parse_global_config ll
   (* TODO: Pas de filtre global pour l'instant
    * le nom de balise contenttype est mauvais, au passage
-     | (Element ("contenttype", [("compress", b)], choices))::ll ->
+     | (Xml.Element ("contenttype", [("compress", b)], choices))::ll ->
        let l = (try parse_filter choices
                with Not_found -> raise (Error_in_config_file
                     "Can't parse mime-type content")) in
