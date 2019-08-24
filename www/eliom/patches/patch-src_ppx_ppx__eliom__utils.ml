$NetBSD: patch-src_ppx_ppx__eliom__utils.ml,v 1.1 2019/08/24 11:07:34 jaapb Exp $

Changes for OCaml 4.08 (patch from upstream)
--- src/ppx/ppx_eliom_utils.ml.orig	2019-02-08 11:31:12.000000000 +0000
+++ src/ppx/ppx_eliom_utils.ml
@@ -232,7 +232,7 @@ module Mli = struct
   let load_file file =
     try
       let items =
-        Pparse.parse_interface ~tool_name:"eliom" Format.err_formatter file
+        Pparse.parse_interface ~tool_name:"eliom" (* Format.err_formatter *) file
       in
       let h = Hashtbl.create 17 in
       let f item = match get_binding item with
@@ -382,7 +382,7 @@ module Cannot_have_fragment = struct
     | Pexp_construct (_,e)
     | Pexp_variant (_,e) -> opt_forall expression e
     | Pexp_let (_,l,e) -> vb_forall expression l && expression e
-    | Pexp_open (_,x,e) -> longident x.txt && expression e
+    | Pexp_open (i,e) -> module_expr i.popen_expr && expression e
     | Pexp_letmodule (_,me,e) -> module_expr me && expression e
 
     (* We could be more precise on those constructs *)
@@ -430,7 +430,7 @@ module Cannot_have_fragment = struct
     | Pstr_primitive _ -> true
     | Pstr_module mb -> module_binding mb
     | Pstr_recmodule mbl -> List.for_all module_binding mbl
-    | Pstr_open x -> longident x.popen_lid.txt
+    | Pstr_open x -> module_expr x.popen_expr
     | Pstr_include x -> module_expr x.pincl_mod
 
     | _ -> false
