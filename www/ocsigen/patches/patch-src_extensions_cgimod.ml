$NetBSD: patch-src_extensions_cgimod.ml,v 1.1 2018/04/13 13:15:00 jaapb Exp $

Write correct request URI
Lwt_chan no longer exists in Lwt 4, replaced by Lwt_io
--- src/extensions/cgimod.ml.orig	2018-02-01 12:55:17.000000000 +0000
+++ src/extensions/cgimod.ml
@@ -271,7 +271,8 @@ let array_environment filename re doc_ro
 
         (* Neither in the CGI's spec nor in the HTTP headers but used, e.g., by PHP *)
         Printf.sprintf "REMOTE_PORT=%d" (Ocsigen_request_info.remote_port ri);
-        Printf.sprintf "REQUEST_URI=%s" (Ocsigen_request_info.url_string ri);
+        Printf.sprintf "REQUEST_URI=%s" (string_conform0 (Ocsigen_request_info.url_string ri));
+
         (* FIXME: URI instead of URL ? *)
         Printf.sprintf "SCRIPT_FILENAME=%s" filename ] ;
       additionnal_headers
@@ -368,7 +369,7 @@ let recupere_cgi head re doc_root filena
     Lwt_timeout.start timeout;
 
     (* A thread giving POST data to the CGI script: *)
-    let post_in_ch = Lwt_chan.out_channel_of_descr post_in in
+    let post_in_ch = Lwt_io.of_fd ~mode:Output post_in in
     ignore
       (catch
          (fun () ->
@@ -376,7 +377,7 @@ let recupere_cgi head re doc_root filena
              | None -> Lwt_unix.close post_in
              | Some content_post ->
                Ocsigen_http_com.write_stream post_in_ch content_post >>= fun () ->
-               Lwt_chan.flush post_in_ch >>= fun () ->
+               Lwt_io.flush post_in_ch >>= fun () ->
                Lwt_unix.close post_in
             ))
          (*XXX Check possible errors! *)
@@ -391,9 +392,9 @@ let recupere_cgi head re doc_root filena
 
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
