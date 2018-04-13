$NetBSD: patch-src_baselib_ocsigen__stream.ml,v 1.1 2018/04/13 13:15:00 jaapb Exp $

Lwt_chan no longer exists in Lwt 4, replaced by Lwt_io
--- src/baselib/ocsigen_stream.ml.orig	2018-02-01 12:55:17.000000000 +0000
+++ src/baselib/ocsigen_stream.ml
@@ -229,10 +229,10 @@ let of_file filename =
   let fd = Lwt_unix.of_unix_file_descr
       (Unix.openfile filename [Unix.O_RDONLY;Unix.O_NONBLOCK] 0o666)
   in
-  let ch = Lwt_chan.in_channel_of_descr fd in
+  let ch = Lwt_io.of_fd ~mode:Input fd in
   let buf = Bytes.create 1024 in
   let rec aux () =
-    Lwt_chan.input ch buf 0 1024 >>= fun n ->
+    Lwt_io.read_into ch buf 0 1024 >>= fun n ->
     if n = 0 then empty None else
       (* Streams should be immutable, thus we always make a copy
          of the buffer *)
