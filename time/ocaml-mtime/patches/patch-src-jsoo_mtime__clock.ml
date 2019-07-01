$NetBSD: patch-src-jsoo_mtime__clock.ml,v 1.1 2019/07/01 16:06:55 jaapb Exp $

Correctly include Js_of_ocaml module
--- src-jsoo/mtime_clock.ml.orig	2017-06-24 16:14:03.000000000 +0000
+++ src-jsoo/mtime_clock.ml
@@ -4,6 +4,8 @@
    mtime v1.1.0
   ---------------------------------------------------------------------------*)
 
+open Js_of_ocaml
+
 let us_to_ns = 1000L (* microsecond to nanosecond uint64 multiplier *)
 
 (* Get a handle on JavaScript's performance.now *)
