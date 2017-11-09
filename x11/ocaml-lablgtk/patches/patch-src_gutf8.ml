$NetBSD: patch-src_gutf8.ml,v 1.1 2017/11/09 10:57:57 jaapb Exp $

Patch to compile with OCaml 4.05 (remove for 4.06!)
--- src/gutf8.ml.orig	2017-10-30 08:37:29.000000000 +0000
+++ src/gutf8.ml
@@ -68,14 +68,14 @@ let write_unichar s ~pos (c : unichar) =
 let from_unichar (n : unichar) =
   let s = Bytes.create 6 and pos = ref 0 in
   write_unichar s ~pos n;
-  Bytes.sub_string s ~pos:0 ~len:!pos
+  Bytes.sub_string s 0 !pos
 
 let from_unistring (s : unistring) =
   let len = Array.length s in
   let r = Bytes.create (len*6) in
   let pos = ref 0 in
   for i = 0 to len-1 do write_unichar r ~pos s.(i) done;
-  Bytes.sub_string r ~pos:0 ~len:!pos
+  Bytes.sub_string r 0 !pos
 
 let rec hi_bits n =
   if n land 0x80 = 0 then 0 else
