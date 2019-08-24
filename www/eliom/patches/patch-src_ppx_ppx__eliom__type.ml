$NetBSD: patch-src_ppx_ppx__eliom__type.ml,v 1.1 2019/08/24 11:07:34 jaapb Exp $

Changes for OCaml 4.08 (patch from upstream)
--- src/ppx/ppx_eliom_type.ml.orig	2019-02-08 11:31:12.000000000 +0000
+++ src/ppx/ppx_eliom_type.ml
@@ -76,7 +76,7 @@ module Pass = struct
       then
         typing_strs :=
           (id,
-           [%stri let [%p Pat.var id] = Pervasives.ref None]
+           [%stri let [%p Pat.var id] = Stdlib.ref None]
            [@metaloc orig_expr.pexp_loc]
           ) :: !typing_strs
     in
