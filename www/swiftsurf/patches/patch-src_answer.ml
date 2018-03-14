$NetBSD: patch-src_answer.ml,v 1.1 2018/03/14 08:58:43 dholland Exp $

Fix build with ocaml 4.06.

--- src/answer.ml~	2002-02-25 18:27:15.000000000 +0000
+++ src/answer.ml
@@ -21,12 +21,12 @@ let rec compute_read conn =
   | CMD_LINE ->
       (try
         let pos = index conn.read_ans '\n' in
-        let cmd = String.sub conn.read_ans.buffer 0 (pos+1) in
+        let cmd = Bytes.sub conn.read_ans.buffer 0 (pos+1) in
         conn.read_ans.pos_deb <- pos+1;
-        Activebuffer.add_string conn.write_ans cmd;
+        Activebuffer.add_bytes conn.write_ans cmd;
         conn.state_ans <- HEADERS;
         if conn.prof.ans_1 then
-          (print_string cmd; flush stdout);
+          (print_bytes cmd; flush stdout);
         compute_read conn
       with Not_found ->
         (* the command line is not finished *)
@@ -34,20 +34,20 @@ let rec compute_read conn =
   | HEADERS ->
       (try
         let pos = index conn.read_ans '\n' in
-        let header = String.sub conn.read_ans.buffer
+        let header = Bytes.sub conn.read_ans.buffer
             conn.read_ans.pos_deb (pos+1-conn.read_ans.pos_deb) in
         conn.read_ans.pos_deb <- pos+1;
-        if String.length header <= 2 then
+        if Bytes.length header <= 2 then
           (* last line of headers *)
           (if conn.prof.ans_1 then
-            (print_string header; flush stdout);
+            (print_bytes header; flush stdout);
            conn.state_ans <- CONTENT;
-           Activebuffer.add_string conn.write_ans header)
+           Activebuffer.add_bytes conn.write_ans header)
         else
-          (if ok_ans_header header then
+          (if ok_ans_header (Bytes.to_string header) then
             (if conn.prof.ans_1 then
-              (print_string header; flush stdout);
-             Activebuffer.add_string conn.write_ans header));
+              (print_bytes header; flush stdout);
+             Activebuffer.add_bytes conn.write_ans header));
         compute_read conn
       with Not_found ->
         (* this line of headers is not finished *)
@@ -100,7 +100,7 @@ let gere_conns time active_read conns =
       let nb = Unix.write conn.client str pos len in
       if nb > 0 then
         (if conn.prof.ans_out then
-           print_string (String.sub str pos nb);
+           print_bytes (Bytes.sub str pos nb);
          sub conn.write_ans nb (len - nb);
          conn.size_ans <- min (conn.size_ans + nb) buf_size;
          conn.timeout <- time +. !Types.timeout)
@@ -134,7 +134,7 @@ let gere_conns time active_read conns =
           false
       | nb ->
           if conn.prof.ans_in then
-            print_string (String.sub str pos nb);
+            print_bytes (Bytes.sub str pos nb);
           after_read conn.read_ans nb;
           conn.timeout <- time +. !Types.timeout;
           conn.size_ans <- conn.size_ans - nb;
