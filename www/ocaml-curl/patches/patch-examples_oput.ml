$NetBSD: patch-examples_oput.ml,v 1.1 2021/08/15 06:10:45 dholland Exp $

Fix build with recent ocaml.

--- examples/oput.ml~	2008-06-23 04:22:56.000000000 +0000
+++ examples/oput.ml
@@ -7,13 +7,13 @@
 let counter = ref 0
 
 let reader file maxBytes =
-  let buffer = String.create maxBytes in
+  let buffer = Bytes.create maxBytes in
   let readBytes = input file buffer 0 maxBytes in
     if readBytes = 0 then ""
     else
       begin
 	counter := !counter + readBytes;
-	String.sub buffer 0 readBytes
+	Bytes.to_string (Bytes.sub buffer 0 readBytes)
       end
 
 let _ =
