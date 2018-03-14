$NetBSD: patch-src_activebuffer.ml,v 1.1 2018/03/14 08:58:43 dholland Exp $

Fix build with ocaml 4.06.

--- src/activebuffer.ml~	2002-01-02 17:14:42.000000000 +0000
+++ src/activebuffer.ml
@@ -1,7 +1,7 @@
 (* Active buffers : can grow and reduce *)
 
 type t = {
-    mutable buffer : string;
+    mutable buffer : bytes;
     mutable pos_deb : int;
     mutable pos_fin : int;
     mutable size : int
@@ -14,15 +14,15 @@ let create n =
    else if n > Sys.max_string_length 
    then Sys.max_string_length 
    else n in
- let s = String.create n in
+ let s = Bytes.create n in
  { buffer = s; pos_deb = 0; pos_fin = 0; size = n }
 
 let activebuffer_of_string str =
   let n = String.length str in
-  { buffer = str; pos_deb = 0; pos_fin = n; size = n }
+  { buffer = (Bytes.of_string str); pos_deb = 0; pos_fin = n; size = n }
 
 let contents b =
-  String.sub b.buffer b.pos_deb (b.pos_fin - b.pos_deb)
+  Bytes.to_string (Bytes.sub b.buffer b.pos_deb (b.pos_fin - b.pos_deb))
 
 let length b = b.pos_fin - b.pos_deb
 
@@ -34,19 +34,19 @@ let resize b more =
   let len = b.pos_fin - b.pos_deb in
   if len + more <= b.size
   then (* no need to resize *)
-    String.blit b.buffer b.pos_deb b.buffer 0 len
+    Bytes.blit b.buffer b.pos_deb b.buffer 0 len
   else
     (let new_len = ref b.size in
      while len + more > !new_len do new_len := 2 * !new_len done;
-     let new_buffer = String.create !new_len in
-     String.blit b.buffer b.pos_deb new_buffer 0 len;
+     let new_buffer = Bytes.create !new_len in
+     Bytes.blit b.buffer b.pos_deb new_buffer 0 len;
      b.buffer <- new_buffer;
      b.size <- !new_len);
   b.pos_deb <- 0; b.pos_fin <- len
       
 let add_char b c =
   if b.pos_fin >= b.size then resize b 1;
-  b.buffer.[b.pos_fin] <- c;
+  Bytes.set b.buffer b.pos_fin c;
   b.pos_fin <- b.pos_fin + 1
 
 let add_substring b s offset len =
@@ -56,14 +56,27 @@ let add_substring b s offset len =
   String.blit s offset b.buffer b.pos_fin len;
   b.pos_fin <- b.pos_fin + len
 
+let add_subbytes b s offset len =
+  if offset < 0 || len < 0 || offset + len > Bytes.length s
+  then invalid_arg "Buffer.add_subbytes";
+  if b.pos_fin + len > b.size then resize b len;
+  Bytes.blit s offset b.buffer b.pos_fin len;
+  b.pos_fin <- b.pos_fin + len
+
 let add_string b s =
   let len = String.length s in
   if b.pos_fin + len > b.size then resize b len;
   String.blit s 0 b.buffer b.pos_fin len;
   b.pos_fin <- b.pos_fin + len
   
+let add_bytes b s =
+  let len = Bytes.length s in
+  if b.pos_fin + len > b.size then resize b len;
+  Bytes.blit s 0 b.buffer b.pos_fin len;
+  b.pos_fin <- b.pos_fin + len
+  
 let add_buffer b bs =
-  add_substring b bs.buffer bs.pos_deb (bs.pos_fin - bs.pos_deb)
+  add_subbytes b bs.buffer bs.pos_deb (bs.pos_fin - bs.pos_deb)
 
 let add_channel b ic len =
   if b.pos_fin + len > b.size then resize b len;
@@ -75,7 +88,7 @@ let output_buffer oc b =
 
 (* the follwing functions do not exist in the original buffer module *)
 let add_subbuffer b bs offset len =
-  add_substring b bs.buffer (bs.pos_deb + offset) len
+  add_subbytes b bs.buffer (bs.pos_deb + offset) len
 
 let sub b offset len =
   if offset < 0 || len < 0 || offset + len > b.pos_fin - b.pos_deb
@@ -96,7 +109,7 @@ let after_read b len =
 
 let rec index_rec s lim i c =
   if i >= lim then raise Not_found else
-  if String.unsafe_get s i = c then i else index_rec s lim (i+1) c;;
+  if Bytes.unsafe_get s i = c then i else index_rec s lim (i+1) c;;
 
 let index b chr =
   index_rec b.buffer b.pos_fin b.pos_deb chr
