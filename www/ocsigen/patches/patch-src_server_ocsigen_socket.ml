$NetBSD: patch-src_server_ocsigen_socket.ml,v 1.1 2017/09/08 17:10:46 jaapb Exp $

Changes to deal with lwt 3.1
--- src/server/ocsigen_socket.ml.orig	2016-11-24 13:31:34.000000000 +0000
+++ src/server/ocsigen_socket.ml
@@ -16,8 +16,8 @@ let make_ipv6_socket addr port =
    * to why set REUSEADDR on socket *)
   Lwt_unix.setsockopt socket Unix.SO_REUSEADDR true;
   Lwt_unix.setsockopt socket Unix.IPV6_ONLY true;
-  Lwt_unix.bind socket (Unix.ADDR_INET (addr, port));
-  socket
+  Lwt_unix.bind socket (Unix.ADDR_INET (addr, port)) >>= fun () ->
+  Lwt.return socket
 
 (** make_ipv4_socket create a socket on an ipv4 address
  * @param addr address of socket
@@ -27,8 +27,8 @@ let make_ipv4_socket addr port =
   let socket = Lwt_unix.socket Unix.PF_INET Unix.SOCK_STREAM 0 in
   Lwt_unix.set_close_on_exec socket;
   Lwt_unix.setsockopt socket Unix.SO_REUSEADDR true;
-  Lwt_unix.bind socket (Unix.ADDR_INET (addr, port));
-  socket
+  Lwt_unix.bind socket (Unix.ADDR_INET (addr, port)) >>= fun () ->
+  Lwt.return socket
 
 let make_sockets addr port =
   match addr with
@@ -39,19 +39,25 @@ let make_sockets addr port =
        corresponds to the net.ipv6.bindv6only=0 behaviour on Linux,
        but is portable and should work with
        net.ipv6.bindv6only=1 as well. *)
-    let ipv6_socket =
-      try [make_ipv6_socket Unix.inet6_addr_any port]
-      with Unix.Unix_error
-          ((Unix.EAFNOSUPPORT
-           | Unix.EPROTONOSUPPORT
-           | Unix.EADDRINUSE (* GH issue #104 *)
-           ), _, _) -> []
-    in
-    (make_ipv4_socket Unix.inet_addr_any port)::ipv6_socket
+    Lwt.catch
+      (fun () ->
+         make_ipv6_socket Unix.inet6_addr_any port >>= fun s ->
+         Lwt.return [s])
+      (function
+        | Unix.Unix_error
+            ((Unix.EAFNOSUPPORT
+             | Unix.EPROTONOSUPPORT
+             | Unix.EADDRINUSE (* GH issue #104 *)
+             ), _, _) ->
+          Lwt.return []
+        | e ->
+          Lwt.fail e) >>= fun ipv6_sockets ->
+    make_ipv4_socket Unix.inet_addr_any port >>= fun ipv4_socket ->
+    Lwt.return (ipv4_socket :: ipv6_sockets)
   | IPv4 addr ->
-    [make_ipv4_socket addr port]
+    make_ipv4_socket addr port >>= fun s -> Lwt.return [s]
   | IPv6 addr ->
-    [make_ipv6_socket addr port]
+    make_ipv6_socket addr port >>= fun s -> Lwt.return [s]
 
 
 let ip_of_sockaddr = function
