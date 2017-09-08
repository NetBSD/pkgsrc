$NetBSD: patch-src_tools_utils.ml,v 1.1 2017/09/08 17:14:34 jaapb Exp $

Changes for js_of_ocaml 3
--- src/tools/utils.ml.orig	2017-02-07 15:42:18.000000000 +0000
+++ src/tools/utils.ml
@@ -265,7 +265,9 @@ let get_common_include ?kind:k ?build_di
   let dir = match dir with Some d -> d | None -> !build_dir in
   (match get_kind k with
    | `Server | `ServerOpt ->
-     map_include (List.map Findlib.package_directory (get_server_package ?kind:k ?package:p ()))
+     "js_of_ocaml" :: get_server_package ?kind:k ?package:p ()
+     |> List.map Findlib.package_directory
+     |> map_include
    | `Client ->
      map_include (List.map Findlib.package_directory (get_client_package ?kind:k ())))
   @ match dir with
@@ -298,8 +300,7 @@ let get_client_lib ?kind:k () =
 let get_client_js () =
   [
     "+eliom.client/eliom_client.js" ;
-    "+js_of_ocaml/weak.js";
-    "+js_of_ocaml/classlist.js" (* ie9 support *)
+    "+js_of_ocaml-compiler/weak.js";
   ]
 
 (* Should be calld only with -dump... *)
