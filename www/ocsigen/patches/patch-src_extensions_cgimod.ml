$NetBSD: patch-src_extensions_cgimod.ml,v 1.4 2020/04/21 11:51:02 jaapb Exp $

Write correct request URI

--- src/extensions/cgimod.ml.orig	2018-12-19 10:54:19.000000000 +0000
+++ src/extensions/cgimod.ml
@@ -270,7 +270,7 @@ let array_environment filename re doc_ro
 
         (* Neither in the CGI's spec nor in the HTTP headers but used, e.g., by PHP *)
         Printf.sprintf "REMOTE_PORT=%d" (Ocsigen_request_info.remote_port ri);
-        Printf.sprintf "REQUEST_URI=%s" (Ocsigen_request_info.url_string ri);
+        Printf.sprintf "REQUEST_URI=%s" (string_conform0 (Ocsigen_request_info.url_string ri));
         (* FIXME: URI instead of URL ? *)
         Printf.sprintf "SCRIPT_FILENAME=%s" filename ] ;
       additionnal_headers
