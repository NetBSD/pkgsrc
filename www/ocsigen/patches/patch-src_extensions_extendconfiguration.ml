$NetBSD: patch-src_extensions_extendconfiguration.ml,v 1.1 2018/11/29 10:54:14 jaapb Exp $

Replace tyxml.parser with xml-light (patch from upstream)
--- src/extensions/extendconfiguration.ml.orig	2018-02-01 12:55:17.000000000 +0000
+++ src/extensions/extendconfiguration.ml
@@ -19,7 +19,6 @@
 *)
 open Lwt
 open Ocsigen_extensions
-open Simplexmlparser
 open Ocsigen_charset_mime
 
 
@@ -50,11 +49,11 @@ let gather_do_not_serve_files tag =
         do_not_serve_extensions = extensions
       }
 
-    | Element ("regexp", ["regexp", f], []) :: q ->
+    | Xml.Element ("regexp", ["regexp", f], []) :: q ->
       aux (f :: regexps, files, extensions) q
-    | Element ("file", ["file", f], []) :: q ->
+    | Xml.Element ("file", ["file", f], []) :: q ->
       aux (regexps, f :: files, extensions) q
-    | Element ("extension", ["ext", f], []) :: q ->
+    | Xml.Element ("extension", ["ext", f], []) :: q ->
       aux (regexps, files, f :: extensions) q
 
     | _ :: q -> bad_config ("invalid options in tag " ^ tag)
@@ -78,14 +77,14 @@ let check_regexp_list =
 
 
 let update_config usermode = function
-  | Element ("listdirs", ["value", "true"], []) ->
+  | Xml.Element ("listdirs", ["value", "true"], []) ->
     gen (fun config -> { config with list_directory_content = true })
-  | Element ("listdirs", ["value", "false"], []) ->
+  | Xml.Element ("listdirs", ["value", "false"], []) ->
     gen (fun config -> { config with list_directory_content = false })
-  | Element ("listdirs" as s, _, _) -> badconfig "Bad syntax for tag %s" s
+  | Xml.Element ("listdirs" as s, _, _) -> badconfig "Bad syntax for tag %s" s
 
 
-  | Element ("followsymlinks", ["value", s], []) ->
+  | Xml.Element ("followsymlinks", ["value", s], []) ->
     let v = match s with
       | "never" -> DoNotFollowSymlinks
       | "always" ->
@@ -100,17 +99,17 @@ let update_config usermode = function
         bad_config ("Wrong value \""^s^"\" for option \"followsymlinks\"")
     in
     gen (fun config -> { config with follow_symlinks = v })
-  | Element ("followsymlinks" as s, _, _) -> badconfig "Bad syntax for tag %s" s
+  | Xml.Element ("followsymlinks" as s, _, _) -> badconfig "Bad syntax for tag %s" s
 
 
-  | Element ("charset", attrs, exts) ->
+  | Xml.Element ("charset", attrs, exts) ->
     let rec aux charset_assoc = function
       | [] -> charset_assoc
-      | Element ("extension", ["ext", extension; "value", charset], []) :: q ->
+      | Xml.Element ("extension", ["ext", extension; "value", charset], []) :: q ->
         aux (update_charset_ext charset_assoc extension charset) q
-      | Element ("file", ["file", file; "value", charset], []) :: q ->
+      | Xml.Element ("file", ["file", file; "value", charset], []) :: q ->
         aux (update_charset_file charset_assoc file charset) q
-      | Element ("regexp", ["regexp", regexp; "value", charset], []) :: q ->
+      | Xml.Element ("regexp", ["regexp", regexp; "value", charset], []) :: q ->
         (try
            let r = Netstring_pcre.regexp regexp in
            aux (update_charset_regexp charset_assoc r charset) q
@@ -129,14 +128,14 @@ let update_config usermode = function
         { config with charset_assoc = aux config.charset_assoc exts })
 
 
-  | Element ("contenttype", attrs, exts) ->
+  | Xml.Element ("contenttype", attrs, exts) ->
     let rec aux mime_assoc = function
       | [] -> mime_assoc
-      | Element ("extension", ["ext", extension; "value", mime], []) :: q ->
+      | Xml.Element ("extension", ["ext", extension; "value", mime], []) :: q ->
         aux (update_mime_ext mime_assoc extension mime) q
-      | Element ("file", ["file", file; "value", mime], []) :: q ->
+      | Xml.Element ("file", ["file", file; "value", mime], []) :: q ->
         aux (update_mime_file mime_assoc file mime) q
-      | Element ("regexp", ["regexp", regexp; "value", mime], []) :: q ->
+      | Xml.Element ("regexp", ["regexp", regexp; "value", mime], []) :: q ->
         (try
            let r = Netstring_pcre.regexp regexp in
            aux (update_mime_regexp mime_assoc r mime) q
@@ -155,10 +154,10 @@ let update_config usermode = function
         { config with mime_assoc = aux config.mime_assoc exts })
 
 
-  | Element ("defaultindex", [], l) ->
+  | Xml.Element ("defaultindex", [], l) ->
     let rec aux indexes = function
       | [] -> List.rev indexes
-      | Element ("index", [], [PCData f]) :: q ->
+      | Xml.Element ("index", [], [PCData f]) :: q ->
         aux (f :: indexes) q
       | _ :: q -> bad_config "subtags must be of the form \
                               <index>...</index> \
@@ -166,9 +165,9 @@ let update_config usermode = function
     in
     gen (fun config ->
         { config with default_directory_index = aux [] l })
-  | Element ("defaultindex" as s, _, _) -> badconfig "Bad syntax for tag %s" s
+  | Xml.Element ("defaultindex" as s, _, _) -> badconfig "Bad syntax for tag %s" s
 
-  | Element ("hidefile", [], l) ->
+  | Xml.Element ("hidefile", [], l) ->
     let do_not_serve = gather_do_not_serve_files "hidefile" l in
     (try
        check_regexp_list do_not_serve.do_not_serve_regexps;
@@ -177,9 +176,9 @@ let update_config usermode = function
                            join_do_not_serve do_not_serve config.do_not_serve_404 })
      with Bad_regexp r ->
        badconfig "Invalid regexp %s in %s" r "hidefile")
-  | Element ("hidefile" as s, _, _) -> badconfig "Bad syntax for tag %s" s
+  | Xml.Element ("hidefile" as s, _, _) -> badconfig "Bad syntax for tag %s" s
 
-  | Element ("forbidfile", [], l) ->
+  | Xml.Element ("forbidfile", [], l) ->
     let do_not_serve = gather_do_not_serve_files "forbidfile" l in
     (try
        check_regexp_list do_not_serve.do_not_serve_regexps;
@@ -188,28 +187,28 @@ let update_config usermode = function
                            join_do_not_serve do_not_serve config.do_not_serve_403 })
      with Bad_regexp r ->
        badconfig "Invalid regexp %s in %s" r "forbidfile")
-  | Element ("forbidfile" as s, _, _) -> badconfig "Bad syntax for tag %s" s
+  | Xml.Element ("forbidfile" as s, _, _) -> badconfig "Bad syntax for tag %s" s
 
-  | Element ("uploaddir", [], [PCData s]) ->
+  | Xml.Element ("uploaddir", [], [PCData s]) ->
     if s = "" then
       gen (fun config -> { config with uploaddir = None })
     else
       gen (fun config -> { config with uploaddir = Some s })
-  | Element ("uploaddir" as s, _, _) ->
+  | Xml.Element ("uploaddir" as s, _, _) ->
     badconfig "Bad syntax for tag %s" s
 
-  | Element ("maxuploadfilesize" as tag, [], [PCData s]) ->
+  | Xml.Element ("maxuploadfilesize" as tag, [], [PCData s]) ->
     let s =
       try Ocsigen_parseconfig.parse_size_tag "uploaddir" s
       with Ocsigen_config.Config_file_error _ ->
         badconfig "Bad syntax for tag %s" tag
     in
     gen (fun config -> { config with maxuploadfilesize = s })
-  | Element ("maxuploadfilesize" as s, _, _) ->
+  | Xml.Element ("maxuploadfilesize" as s, _, _) ->
     badconfig "Bad syntax for tag %s" s
 
 
-  | Element (t, _, _) -> raise (Bad_config_tag_for_extension t)
+  | Xml.Element (t, _, _) -> raise (Bad_config_tag_for_extension t)
   | _ ->
     raise (Error_in_config_file "Unexpected data in config file")
 
