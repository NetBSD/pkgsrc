$NetBSD: patch-src_tools_eliomc.ml,v 1.1 2019/08/24 11:07:34 jaapb Exp $

Changes for OCaml 4.08 (patch from upstream)
--- src/tools/eliomc.ml.orig	2019-02-08 11:31:12.000000000 +0000
+++ src/tools/eliomc.ml
@@ -211,6 +211,7 @@ let inferred_type_prefix = "eliom_inferr
    These appear in type_mli files, but they are not accepted by
    the OCaml parser.  *)
 let run_sed file =
+	run_command ("sed -i -e 's$/[1-9][0-9]*$$g' " ^ file);
   run_command ("sed -i -e 's/_\\[\\([<>]\\)/[\\1/g' " ^ file);
   run_command
     (Printf.sprintf
