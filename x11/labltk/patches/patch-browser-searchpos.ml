$NetBSD: patch-browser-searchpos.ml,v 1.1 2017/09/10 02:36:08 dholland Exp $

Revert part of the upstream changes since we don't have ocaml 4.06
in pkgsrc yet and the new version doesn't compile.

--- browser/searchpos.ml~	2017-07-19 03:52:12.000000000 +0000
+++ browser/searchpos.ml
@@ -782,7 +782,7 @@ and search_pos_expr ~pos exp =
         search_pos_expr exp' ~pos
       end;
       search_pos_expr exp ~pos
-  | Texp_function {cases=l; _} ->
+  | Texp_function (*{cases=l; _}*) (_, l, _) ->
       List.iter l ~f:(search_case ~pos)
   | Texp_apply (exp, l) ->
       List.iter l ~f:(fun (_, x) -> Misc.may (search_pos_expr ~pos) x);
