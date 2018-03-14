$NetBSD: patch-request.ml,v 1.1 2018/03/14 08:58:43 dholland Exp $

Fix build with ocaml 4.06.

--- src/request.ml~	2002-03-04 11:46:08.000000000 +0000
+++ src/request.ml
@@ -68,7 +68,7 @@ let goto_content conn =
   try
     conn.prof <- Conf.get_profile conn.auth;
     if conn.prof.req_in then
-      (print_string (String.sub conn.read_req.buffer 0
+      (print_bytes (Bytes.sub conn.read_req.buffer 0
                        conn.read_req.pos_fin);
        flush stdout);
     if conn.prof.req_1 then
@@ -101,12 +101,12 @@ let verif_auth conn deb len =
     let rec aux i =
       if i == len2
       then true
-      else str.[i] == (Char.lowercase conn.read_req.buffer.[deb+i])
+      else str.[i] == (Char.lowercase_ascii (Bytes.get conn.read_req.buffer (deb+i)))
           && aux (i+1) in
     if aux 0
     then
-      (conn.auth <- decode64 (String.sub conn.read_req.buffer
-                                (deb+len2+6) (len-len2-8));
+      (conn.auth <- decode64 (Bytes.to_string (Bytes.sub conn.read_req.buffer
+                                (deb+len2+6) (len-len2-8)));
        false)
     else true
   with _ -> false
@@ -203,7 +203,7 @@ let rec compute_read conn =
   | CMD_LINE ->
       (try
         let pos = index conn.read_req '\n' in
-        let cmd = String.sub conn.read_req.buffer 0 (pos+1) in
+        let cmd = Bytes.to_string (Bytes.sub conn.read_req.buffer 0 (pos+1)) in
         conn.read_req.pos_deb <- pos+1;
         gere_cmdline cmd conn;
         match conn.state_req with
@@ -237,8 +237,8 @@ let rec compute_read conn =
       (try
         let pos = index conn.read_req '\n' in
         let len = pos + 1 - conn.read_req.pos_deb in
-        let header = String.sub conn.read_req.buffer
-            conn.read_req.pos_deb len in
+        let header = Bytes.to_string (Bytes.sub conn.read_req.buffer
+            conn.read_req.pos_deb len) in
         let deb = conn.read_req.pos_deb in
         conn.read_req.pos_deb <- pos+1;
         if len <= 2 then
@@ -393,7 +393,7 @@ let gere_conns time active_read active_w
       let nb = Unix.write conn.server str pos len in
       if nb > 0 then
         (if conn.prof.req_out then
-           print_string (String.sub str pos nb);
+           print_bytes (Bytes.sub str pos nb);
          sub conn.write_req nb (len - nb);
          conn.size_req <- min (conn.size_req + nb) buf_size;
          conn.timeout <- time +. !Types.timeout);
@@ -419,7 +419,7 @@ let gere_conns time active_read active_w
           false
       | nb ->
           if conn.prof.req_in then
-            print_string (String.sub str pos nb);
+            print_bytes (Bytes.sub str pos nb);
           after_read conn.read_req nb;
           conn.timeout <- time +. !Types.timeout;
           conn.size_req <- conn.size_req - nb;
