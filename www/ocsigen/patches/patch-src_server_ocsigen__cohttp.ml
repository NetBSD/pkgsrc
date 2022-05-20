$NetBSD: patch-src_server_ocsigen__cohttp.ml,v 1.1 2022/05/20 07:04:07 jaapb Exp $

Deal with changes in newer version of cohttp (patch from upstream)

--- src/server/ocsigen_cohttp.ml.orig	2022-01-21 16:20:49.000000000 +0000
+++ src/server/ocsigen_cohttp.ml
@@ -14,13 +14,13 @@ exception Ext_http_error of
 
 let _print_request fmt request =
 
-  let print_list print_data out_ch lst =
+  (* let print_list print_data out_ch lst =
     let rec aux = function
       | [] -> ()
       | [ x ] -> print_data out_ch x
       | x :: r -> print_data out_ch x; aux r
     in aux lst
-  in
+  in *)
 
   Format.fprintf fmt "%s [%s/%s]:\n"
     (Uri.to_string (Cohttp.Request.uri request))
@@ -29,10 +29,7 @@ let _print_request fmt request =
 
   Cohttp.Header.iter
     (fun key values ->
-       (print_list
-          (fun fmt value -> Format.fprintf fmt "\t%s = %s\n" key value)
-          fmt
-          values))
+       Format.fprintf fmt "\t%s = %s\n" key values)
     (Cohttp.Request.headers request)
 
 let connections = Hashtbl.create 256
