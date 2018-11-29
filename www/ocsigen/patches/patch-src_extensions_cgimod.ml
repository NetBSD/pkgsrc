$NetBSD: patch-src_extensions_cgimod.ml,v 1.2 2018/11/29 10:54:14 jaapb Exp $

Write correct request URI
Lwt_chan no longer exists in Lwt 4, replaced by Lwt_io
Replace tyxml.parser with xml-light (patch from upstream)
--- src/extensions/cgimod.ml.orig	2018-02-01 12:55:17.000000000 +0000
+++ src/extensions/cgimod.ml
@@ -28,7 +28,6 @@ open Ocsigen_lib
 
 open Lwt
 open Ocsigen_extensions
-open Simplexmlparser
 open Ocsigen_http_frame
 open Ocsigen_http_com
 open Ocsigen_senders
@@ -271,7 +270,8 @@ let array_environment filename re doc_ro
 
         (* Neither in the CGI's spec nor in the HTTP headers but used, e.g., by PHP *)
         Printf.sprintf "REMOTE_PORT=%d" (Ocsigen_request_info.remote_port ri);
-        Printf.sprintf "REQUEST_URI=%s" (Ocsigen_request_info.url_string ri);
+        Printf.sprintf "REQUEST_URI=%s" (string_conform0 (Ocsigen_request_info.url_string ri));
+
         (* FIXME: URI instead of URL ? *)
         Printf.sprintf "SCRIPT_FILENAME=%s" filename ] ;
       additionnal_headers
@@ -368,7 +368,7 @@ let recupere_cgi head re doc_root filena
     Lwt_timeout.start timeout;
 
     (* A thread giving POST data to the CGI script: *)
-    let post_in_ch = Lwt_chan.out_channel_of_descr post_in in
+    let post_in_ch = Lwt_io.of_fd ~mode:Output post_in in
     ignore
       (catch
          (fun () ->
@@ -376,7 +376,7 @@ let recupere_cgi head re doc_root filena
              | None -> Lwt_unix.close post_in
              | Some content_post ->
                Ocsigen_http_com.write_stream post_in_ch content_post >>= fun () ->
-               Lwt_chan.flush post_in_ch >>= fun () ->
+               Lwt_io.flush post_in_ch >>= fun () ->
                Lwt_unix.close post_in
             ))
          (*XXX Check possible errors! *)
@@ -391,9 +391,9 @@ let recupere_cgi head re doc_root filena
 
     (* A thread listening the error output of the CGI script
        and writing them in warnings.log *)
-    let err_channel = Lwt_chan.in_channel_of_descr err_out in
+    let err_channel = Lwt_io.of_fd ~mode:Input err_out in
     let rec get_errors () =
-      Lwt_chan.input_line err_channel >>= fun err ->
+      Lwt_io.read_line err_channel >>= fun err ->
       Lwt_log.ign_warning ~section err;
       get_errors ()
     in ignore
@@ -456,7 +456,7 @@ let get_content str =
 (*****************************************************************************)
 let rec parse_global_config = function
   | [] -> ()
-  | (Element ("cgitimeout", [("value", s)], []))::[] ->
+  | (Xml.Element ("cgitimeout", [("value", s)], []))::[] ->
     cgitimeout := int_of_string s
   | _ -> raise (Error_in_config_file
                   ("Unexpected content inside cgimod config"))
@@ -573,7 +573,7 @@ let gen reg = function
 
 let rec set_env = function
   | [] -> []
-  | (Element("setenv", [("var",vr);("val",vl)], []))::l ->
+  | (Xml.Element("setenv", [("var",vr);("val",vl)], []))::l ->
     if List.mem vr environment
     then (Lwt_log.ign_info_f ~section "Variable no set %s" vr;
           set_env l)
@@ -581,7 +581,7 @@ let rec set_env = function
   | _ :: l -> raise (Error_in_config_file "Bad config tag for <cgi>")
 
 let parse_config _ path _ _ = function
-  | Element ("cgi", atts, l) ->
+  | Xml.Element ("cgi", atts, l) ->
     let good_root r =
       Regexp.quote (string_conform2 r)
     in
