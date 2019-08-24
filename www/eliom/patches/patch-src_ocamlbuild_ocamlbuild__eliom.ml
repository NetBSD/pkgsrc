$NetBSD: patch-src_ocamlbuild_ocamlbuild__eliom.ml,v 1.1 2019/08/24 11:07:34 jaapb Exp $

Changes for OCaml 4.08 (patch from upstream)
--- src/ocamlbuild/ocamlbuild_eliom.ml.orig	2019-02-08 11:31:12.000000000 +0000
+++ src/ocamlbuild/ocamlbuild_eliom.ml
@@ -188,7 +188,8 @@ module MakeIntern (I : INTERNALS)(Eliom 
         sed_rule ".inferred.mli -> .inferred_gen.mli"
           ~dep:"%(path)/%(file).inferred.mli"
           ~prod:"%(path)/%(file).inferred_gen.mli"
-          ["s/_\\[\\([<>]\\)/[\\1/g";
+          ["s$/[1-9][0-9]*$$g";
+					 "s/_\\[\\([<>]\\)/[\\1/g";
            Printf.sprintf "s/'\\(_[a-z0-9_]*\\)/'%s\\1/g" inferred_type_prefix];
 
         (* eliom files *)
