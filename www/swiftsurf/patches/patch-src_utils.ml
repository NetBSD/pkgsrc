$NetBSD: patch-src_utils.ml,v 1.1 2018/03/14 08:58:43 dholland Exp $

Fix build with ocaml 4.06.

--- src/utils.ml~	2002-02-06 21:32:06.000000000 +0000
+++ src/utils.ml
@@ -55,7 +55,7 @@ let finish conn str =
 let read_file name =
   let chan = open_in_bin name in
   let buf_size = ref 1024 in
-  let buf = ref (String.create !buf_size) in
+  let buf = ref (Bytes.create !buf_size) in
   let nb_read = ref 0 in
   let cont = ref true in
   while !cont do
@@ -66,11 +66,11 @@ let read_file name =
       (nb_read := !nb_read + tmp;
        if !nb_read = !buf_size
        then
-         (buf := !buf ^ (String.create !buf_size);
+         (buf := Bytes.extend !buf 0 !buf_size;
           buf_size := 2 * !buf_size))
   done;
   close_in chan;
-  String.sub !buf 0 !nb_read
+  Bytes.to_string (Bytes.sub !buf 0 !nb_read)
 
 (* hack for using the parser *)
 let pars = ref (fun x -> assert false)
@@ -97,7 +97,7 @@ let match_pattern str pat =
         | '*' ->
             match_aux (pos_s+1) pos_p
         | '?' -> match_aux (pos_s+1) (pos_p+1)
-        | x -> x = (Char.lowercase str.[pos_s])
+        | x -> x = (Char.lowercase_ascii str.[pos_s])
               && match_aux (pos_s+1) (pos_p+1))))
   in
   match_aux 0 0
@@ -116,7 +116,7 @@ let decode64 s =
       | _ -> failwith "not a base64 string" in
     let len = String.length s in
     let len_res = len * 3 / 4 in
-    let res = String.create len_res in
+    let res = Bytes.create len_res in
     for i=0 to len/4 - 1 do
       let i1 = 4*i and i2 = 3*i in
       let v1 = (val64 s.[i1]) lsl 18 in
@@ -124,15 +124,15 @@ let decode64 s =
       let v3 = (val64 s.[i1 + 2]) lsl 6 in
       let v4 = val64 s.[i1 + 3] in
       let v = v1 lor v2 lor v3 lor v4 in
-      res.[i2] <- Char.chr (v lsr 16);
-      res.[i2 + 1] <- Char.chr (v lsr 8 land 0xFF);
-      res.[i2 + 2] <- Char.chr (v land 0xFF)
+      Bytes.set res i2  (Char.chr (v lsr 16));
+      Bytes.set res (i2 + 1) (Char.chr (v lsr 8 land 0xFF));
+      Bytes.set res (i2 + 2) (Char.chr (v land 0xFF))
     done;
     let nb_keep =
       if s.[len-1] = '=' then
         if s.[len-2] = '=' then len_res - 2 else len_res - 1
       else len_res in
-    String.sub res 0 nb_keep
+    Bytes.to_string (Bytes.sub res 0 nb_keep)
 
 (* encode passwd for authentication *)
 let encode64 s =
@@ -144,25 +144,25 @@ let encode64 s =
        '0'; '1'; '2'; '3'; '4'; '5'; '6'; '7'; '8'; '9'; '+'; '/' |] in
   let len = String.length s in
   let lenres = if len = 0 then 0 else ((len - 1) / 3 + 1) * 4 in
-  let res = String.make lenres '=' in
+  let res = Bytes.make lenres '=' in
   for i = 0 to len / 3 - 1 do
     let v = (Char.code (s.[3*i]) lsl 16) +
         (Char.code (s.[3*i+1]) lsl 8) + (Char.code (s.[3*i+2])) in
-    res.[4*i] <- b64.(v lsr 18);
-    res.[4*i+1] <- b64.((v lsr 12) mod 64);
-    res.[4*i+2] <- b64.((v lsr 6) mod 64);
-    res.[4*i+3] <- b64.(v mod 64)
+    Bytes.set res (4*i) (b64.(v lsr 18));
+    Bytes.set res (4*i+1) (b64.((v lsr 12) mod 64));
+    Bytes.set res (4*i+2) (b64.((v lsr 6) mod 64));
+    Bytes.set res (4*i+3) (b64.(v mod 64))
   done;
   (match len mod 3 with
   | 0 -> ()
   | 1 ->
       let v = Char.code s.[len-1] in
-      res.[lenres-4] <- b64.(v lsr 2);
-      res.[lenres-3] <- b64.((v mod 4) lsl 4)
+      Bytes.set res (lenres-4) (b64.(v lsr 2));
+      Bytes.set res (lenres-3) (b64.((v mod 4) lsl 4))
   | 2 ->
       let v = (Char.code (s.[len-2]) lsl 8) + (Char.code (s.[len-1])) in
-      res.[lenres-4] <- b64.(v lsr 10);
-      res.[lenres-3] <- b64.((v lsr 4) mod 64);
-      res.[lenres-2] <- b64.((v mod 16) lsl 2)
+      Bytes.set res (lenres-4) (b64.(v lsr 10));
+      Bytes.set res (lenres-3) (b64.((v lsr 4) mod 64));
+      Bytes.set res (lenres-2) (b64.((v mod 16) lsl 2))
   | _ -> assert false);
-  res
+  Bytes.to_string res
