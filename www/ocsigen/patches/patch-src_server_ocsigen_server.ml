$NetBSD: patch-src_server_ocsigen_server.ml,v 1.1 2017/09/08 17:10:46 jaapb Exp $

Changes to deal with lwt 3.1
--- src/server/ocsigen_server.ml.orig	2016-11-24 13:31:34.000000000 +0000
+++ src/server/ocsigen_server.ml
@@ -1134,23 +1134,26 @@ let start_server () =
   let stop n fmt = Printf.ksprintf (fun s -> raise (Stop (n, s))) fmt in
   (** Thread waiting for events on a the listening port *)
   let listen use_ssl (addr, port) wait_end_init =
-    let listening_sockets =
-      try
-        let sockets = make_sockets addr port in
-        List.iter (fun x -> Lwt_unix.listen x 1024) sockets;
-        sockets
-      with
-      | Unix.Unix_error (Unix.EACCES, _, _) ->
-        stop 7 "Fatal - You are not allowed to use port %d." port
-      | Unix.Unix_error (Unix.EADDRINUSE, _, _) ->
-        stop 8 "Fatal - The port %d is already in use." port
-      | exn ->
-        stop 100 "Fatal - Uncaught exception: %s" (Printexc.to_string exn)
-    in
-    List.iter (fun x ->
-      ignore (wait_end_init >>= fun () ->
-              wait_connection use_ssl port x)) listening_sockets;
-    listening_sockets
+    Lwt.catch
+      (fun () ->
+         make_sockets addr port >>= fun sockets ->
+         Lwt_list.iter_s
+           (fun x -> Lwt_unix.listen x 1024; Lwt.return ())
+           sockets >>= fun () ->
+         Lwt.return sockets)
+      (function
+        | Unix.Unix_error (Unix.EACCES, _, _) ->
+          stop 7 "Fatal - You are not allowed to use port %d." port
+        | Unix.Unix_error (Unix.EADDRINUSE, _, _) ->
+          stop 8 "Fatal - The port %d is already in use." port
+        | exn ->
+          stop 100 "Fatal - Uncaught exception: %s"
+            (Printexc.to_string exn)) >>= fun listening_sockets ->
+    List.iter
+      (fun x ->
+         ignore (wait_end_init >>= fun () ->
+                 wait_connection use_ssl port x)) listening_sockets;
+    Lwt.return listening_sockets
   in
   try
 
@@ -1192,10 +1195,20 @@ let start_server () =
 
       let wait_end_init, wait_end_init_awakener = wait () in
       (* Listening on all ports: *)
-      sockets := List.fold_left
-          (fun a i -> (listen false i wait_end_init) @ a) [] ports;
-      sslsockets := List.fold_left
-          (fun a i -> (listen true i wait_end_init) @ a) [] sslports;
+
+      Lwt_list.fold_left_s
+        (fun a i ->
+           listen false i wait_end_init >>= fun l ->
+           Lwt.return (l @ a))
+        [] ports >>= fun l ->
+      sockets := l;
+
+      Lwt_list.fold_left_s
+        (fun a i ->
+           listen true i wait_end_init >>= fun l ->
+           Lwt.return (l @ a))
+        [] sslports >>= fun l ->
+      sslsockets := l;
 
       begin match ports with
         | (_, p)::_ -> Ocsigen_config.set_default_port p
