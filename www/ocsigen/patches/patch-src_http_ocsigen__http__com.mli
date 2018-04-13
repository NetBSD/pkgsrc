$NetBSD: patch-src_http_ocsigen__http__com.mli,v 1.1 2018/04/13 13:15:00 jaapb Exp $

Lwt_chan no longer exists in Lwt 4, replaced by Lwt_io
--- src/http/ocsigen_http_com.mli.orig	2018-02-01 12:55:17.000000000 +0000
+++ src/http/ocsigen_http_com.mli
@@ -69,7 +69,7 @@ val wait_all_senders : connection -> uni
    interrupted stream exception.
 *)
 val write_stream :
-  ?chunked:bool -> Lwt_chan.out_channel -> string Ocsigen_stream.t -> unit Lwt.t
+  ?chunked:bool -> Lwt_io.output_channel -> string Ocsigen_stream.t -> unit Lwt.t
 
 (****)
 
