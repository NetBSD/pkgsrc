$NetBSD: patch-src_dns.ml,v 1.1 2018/03/14 08:58:43 dholland Exp $

Fix build with ocaml 4.06.

--- src/dns.ml~	2002-02-25 18:27:15.000000000 +0000
+++ src/dns.ml
@@ -59,7 +59,7 @@ let read_value fds =
   let header = really_read fds Marshal.header_size in
   let ds = Marshal.data_size header 0 in
   let data = really_read fds ds in
-  Marshal.from_string (header^data) 0
+  Marshal.from_string ((Bytes.to_string header) ^ (Bytes.to_string data)) 0
 
 (*************)
 (* dns cache *)
