$NetBSD: patch-pkg_build.ml,v 1.3 2019/08/24 11:07:34 jaapb Exp $

Do not install mime types
Do not build syntax package (patch from upstream)
--- pkg/build.ml.orig	2019-02-08 11:31:12.000000000 +0000
+++ pkg/build.ml
@@ -75,12 +75,6 @@ let () =
     Pkg.bin ~auto:true ~dst:"eliom-distillery" "src/tools/distillery";
     Pkg.bin ~auto:true "src/ocamlbuild/eliombuild";
 
-    (* SYNTAXES *)
-    Pkg.lib ~exts:exts_syntax ~dst:"syntax/pa_eliom_seed" "src/syntax/pa_eliom_seed";
-    Pkg.lib ~exts:exts_syntax ~dst:"syntax/pa_eliom_client_client" "src/syntax/pa_eliom_client_client";
-    Pkg.lib ~exts:exts_syntax ~dst:"syntax/pa_eliom_client_server" "src/syntax/pa_eliom_client_server";
-    Pkg.lib ~exts:exts_syntax ~dst:"syntax/pa_eliom_type_filter" "src/syntax/pa_eliom_type_filter";
-
     Pkg.lib ~exts:exts_modlib ~dst:"ocamlbuild/ocamlbuild_eliom" "src/ocamlbuild/ocamlbuild_eliom";
 
     (* PPX *)
@@ -109,8 +103,7 @@ let () =
     (* MISC *)
 
     Pkg.doc "README.md";
-    Pkg.doc "CHANGES";
-    Pkg.etc "pkg/etc/mime.types"
+    Pkg.doc "CHANGES"
   ] @ (
     List.flatten (
       List.map (fun (name,files) ->
