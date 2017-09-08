$NetBSD: patch-src_ocamlbuild_ocamlbuild_eliom.ml,v 1.1 2017/09/08 17:14:34 jaapb Exp $

Changes for js_of_ocaml 3
--- src/ocamlbuild/ocamlbuild_eliom.ml.orig	2017-02-07 15:42:18.000000000 +0000
+++ src/ocamlbuild/ocamlbuild_eliom.ml
@@ -134,6 +134,10 @@ module MakeIntern (I : INTERNALS)(Eliom 
     dflag ["ocaml"; "infer_interface"; file_tag] ppflags;
     dflag ["ocaml"; "doc";             file_tag] ppflags_notype
 
+  let ocamlfind_query pkg =
+    let cmd = Printf.sprintf "ocamlfind query %s" (Filename.quote pkg) in
+    Ocamlbuild_pack.My_unix.run_and_open cmd input_line
+
   let copy_rule_server ?(eliom=true) =
     copy_rule_with_header
       (fun env dir name src file ->
@@ -143,6 +147,9 @@ module MakeIntern (I : INTERNALS)(Eliom 
              :: get_syntaxes eliom `Server src
            );
          if eliom then flag_infer ~file ~name ~path `Server;
+         dflag ["ocaml"; "compile"; "file:" ^ file]
+           (S [A "-I";
+               A (ocamlfind_query "js_of_ocaml")]);
          Pathname.define_context dir [path];
          Pathname.define_context path [dir];
       )
