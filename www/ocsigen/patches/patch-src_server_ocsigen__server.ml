$NetBSD: patch-src_server_ocsigen__server.ml,v 1.2 2018/11/29 10:54:14 jaapb Exp $

Lwt_chan no longer exists in Lwt 4, replaced by Lwt_io
Replace tyxml.parser with xml-light (patch from upstream)
--- src/server/ocsigen_server.ml.orig	2018-02-01 12:55:17.000000000 +0000
+++ src/server/ocsigen_server.ml
@@ -1029,9 +1029,12 @@ let errmsg = function
   | Ocsigen_extensions.Error_in_config_file msg ->
     (("Fatal - Error in configuration file: "^msg),
      50)
-  | Simplexmlparser.Xml_parser_error s ->
-    (("Fatal - Error in configuration file: "^s),
-     51)
+  | Xml.Error (s, loc) ->
+    let begin_char, end_char = Xml.range loc and line = Xml.line loc in
+    raise (Ocsigen_extensions.Error_in_config_file
+             (Printf.sprintf "%s, line %d, characters %d-%d"
+                (Xml.error_msg s)
+                line begin_char end_char))
   | Ocsigen_loader.Dynlink_error (s, exn) ->
     (("Fatal - While loading "^s^": "^(Printexc.to_string exn)),
      52)
@@ -1317,13 +1320,13 @@ let start_server () =
 
       Ocsigen_extensions.end_initialisation ();
 
-      let pipe = Lwt_chan.in_channel_of_descr
+      let pipe = Lwt_io.of_fd ~mode:Input
           (Lwt_unix.of_unix_file_descr
              (Unix.openfile commandpipe
                 [Unix.O_RDWR; Unix.O_NONBLOCK; Unix.O_APPEND] 0o660)) in
 
       let rec f () =
-        Lwt_chan.input_line pipe >>= fun s ->
+        Lwt_io.read_line pipe >>= fun s ->
         Lwt_log.ign_notice ~section ("Command received: "^s);
         (Lwt.catch
            (fun () ->
