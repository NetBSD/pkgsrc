$NetBSD: patch-src_activebuffer.mli,v 1.1 2018/03/14 08:58:43 dholland Exp $

Fix build with ocaml 4.06.

--- src/activebuffer.mli~	2002-01-02 17:14:42.000000000 +0000
+++ src/activebuffer.mli
@@ -1,5 +1,5 @@
 type t = {
-    mutable buffer : string;
+    mutable buffer : bytes;
     mutable pos_deb : int;
     mutable pos_fin : int;
     mutable size : int
@@ -22,6 +22,9 @@ val add_char : t -> char -> unit
 val add_string : t -> string -> unit
      (*d [add_string b s] appends the string [s] at the end of
         the buffer [b]. *)
+val add_bytes : t -> bytes -> unit
+     (*d [add_bytes b s] appends the bytes [s] at the end of
+        the buffer [b]. *)
 val add_substring : t -> string -> int -> int -> unit
      (*d [add_substring b s ofs len] takes [len] characters from offset
         [ofs] in string [s] and appends them at the end of the buffer [b]. *)
@@ -50,7 +53,7 @@ val sub : t -> int -> int -> unit
         starting at offset [pos] and of length [len]. This function
         does not copy nor create strings. Raise [Invalid_argument]
         if [pos] and [len] do not designate a valid sub_part of the buffer *)
-val buffer : t -> string*int
+val buffer : t -> bytes*int
     (*d [buffer b] gives the internal string used by the buffer and the
        starting active posistion. It can be used in conjunction with
        [sub] when doing [write] in order to avoid unnecessary copy.
@@ -58,7 +61,7 @@ val buffer : t -> string*int
         let str, pos = buffer b in
         let nb_written = write fds str pos len in
         sub b nb_written (len - nb_written)] *)
-val before_read : t -> int -> string*int
+val before_read : t -> int -> bytes*int
 val after_read : t -> int -> unit
     (*d [buffer b] gives the internal string used by the buffer and the
        starting active posistion. It can be used in conjunction with
