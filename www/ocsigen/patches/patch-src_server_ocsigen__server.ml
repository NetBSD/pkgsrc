$NetBSD: patch-src_server_ocsigen__server.ml,v 1.1 2018/04/13 13:15:00 jaapb Exp $

Lwt_chan no longer exists in Lwt 4, replaced by Lwt_io
--- src/server/ocsigen_server.ml.orig	2018-02-01 12:55:17.000000000 +0000
+++ src/server/ocsigen_server.ml
@@ -1317,13 +1317,13 @@ let start_server () =
 
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
