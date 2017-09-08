$NetBSD: patch-src_server_ocsigen_socket.mli,v 1.1 2017/09/08 17:10:46 jaapb Exp $

Changes to deal with lwt 3.1
--- src/server/ocsigen_socket.mli.orig	2016-11-24 13:31:34.000000000 +0000
+++ src/server/ocsigen_socket.mli
@@ -10,7 +10,7 @@ type socket_type =
     @param addr type of addresss (All | IPv4 | IPv6)
     @param port port of socket
 *)
-val make_sockets : socket_type -> int -> Lwt_unix.file_descr list
+val make_sockets : socket_type -> int -> Lwt_unix.file_descr list Lwt.t
 
 (** ip_of_sockaddr accessor for ip
     @param A Unix.ADDR_INET value or raise error
