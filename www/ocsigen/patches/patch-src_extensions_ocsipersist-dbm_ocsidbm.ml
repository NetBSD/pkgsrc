$NetBSD: patch-src_extensions_ocsipersist-dbm_ocsidbm.ml,v 1.1 2017/09/08 17:10:46 jaapb Exp $

Changes to deal with lwt 3.1
--- src/extensions/ocsipersist-dbm/ocsidbm.ml.orig	2016-11-24 13:31:34.000000000 +0000
+++ src/extensions/ocsipersist-dbm/ocsidbm.ml
@@ -272,9 +272,12 @@ let rec loop socket =
 
 let _ = Lwt_main.run
     (let socket = Lwt_unix.socket Unix.PF_UNIX Unix.SOCK_STREAM 0 in
-     (try
-        Lwt_unix.bind socket (Unix.ADDR_UNIX (directory^"/"^socketname))
-      with _ -> errlog ("Please make sure that the directory "^directory^" exists, writable for ocsidbm, and no other ocsidbm process is running on the same directory. If not, remove the file "^(directory^"/"^socketname)); the_end 1);
+	Lwt.catch
+     (fun () ->
+        Lwt_unix.bind socket (Unix.ADDR_UNIX (directory^"/"^socketname)))
+     (fun exn ->
+	errlog ("Please make sure that the directory "^directory^" exists, writable for ocsidbm, and no other ocsidbm process is running on the same directory. If not, remove the file "^(directory^"/"^socketname));
+	the_end 1) >>= fun () ->
      Lwt_unix.listen socket 20;
      (* Done in ocsipersist.ml
         let devnull = Unix.openfile "/dev/null" [Unix.O_WRONLY] 0 in
