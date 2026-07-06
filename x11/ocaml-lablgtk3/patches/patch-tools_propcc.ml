$NetBSD: patch-tools_propcc.ml,v 1.1 2026/07/06 14:51:55 wiz Exp $

ocaml-dune-3.24 compat
https://github.com/garrigue/lablgtk/pull/195

--- tools/propcc.ml.orig	2024-06-10 03:22:38.000000000 +0000
+++ tools/propcc.ml
@@ -549,7 +549,7 @@ let process_file f =
 let ooutfile = ref ""
 
 let process_file f =
-  let base = Filename.chop_extension f in
+  let base = Filename.chop_extension (Filename.basename f) in
   let baseM = String.capitalize_ascii base in
   prefix := baseM;
   (* Input *)
