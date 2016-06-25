$NetBSD: patch-src_pxp-engine_pxp-document.ml,v 1.1 2016/06/25 13:59:21 jaapb Exp $

Comment out multiply-defined exception
--- src/pxp-engine/pxp_document.ml.orig	2016-03-03 13:46:50.000000000 +0000
+++ src/pxp-engine/pxp_document.ml
@@ -3398,7 +3398,7 @@ let find_all_elements ?deeply eltype bas
 ;;
 
 
-exception Skip;;
+(* exception Skip;; *)
 
 let map_tree ~pre ?(post=(fun x -> x)) base =
   let rec map_rec n =
