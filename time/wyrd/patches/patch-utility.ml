$NetBSD: patch-utility.ml,v 1.1 2018/03/14 09:14:05 dholland Exp $

Fix build with ocaml 4.06.

--- utility.ml~	2013-02-03 03:40:39.000000000 +0000
+++ utility.ml
@@ -270,7 +270,7 @@ let read_all_shell_command_output shell_
          let (read_list, _, _) = Unix.select (out_lst @ err_lst) [] [] (10.0) in
          if List.length read_list > 0 then begin
             let chan = List.hd read_list in
-            let buf = String.make 256 ' ' in
+            let buf = Bytes.make 256 ' ' in
             let chars_read = Unix.read chan buf 0 256 in
             if chars_read = 0 then
                (* no chars read indicates EOF *)
@@ -281,7 +281,7 @@ let read_all_shell_command_output shell_
             else
                (* if 1-256 characters are read, append them to the proper
                 * buffer and continue *)
-               let s = String.sub buf 0 chars_read in
+               let s = Bytes.to_string (Bytes.sub buf 0 chars_read) in
                if chan = out_read then
                   read_output (out_str ^ s) err_str out_done err_done
                else
@@ -354,11 +354,11 @@ let utf8_string_before s n =
          substr
       else
          let num_new_bytes = utf8_width s.[byte_pos] in
-         let new_bytes = String.make num_new_bytes s.[byte_pos] in
+         let new_bytes = Bytes.make num_new_bytes s.[byte_pos] in
          for i = 1 to pred num_new_bytes do
-            new_bytes.[i] <- s.[byte_pos + i]
+            Bytes.set new_bytes i s.[byte_pos + i]
          done;
-         build_substr (substr ^ new_bytes) (succ utf8_pos) 
+         build_substr (substr ^ (Bytes.to_string new_bytes)) (succ utf8_pos) 
             (byte_pos + num_new_bytes)
    in
    if Curses.Curses_config.wide_ncurses then
