$NetBSD: patch-src_lib_client_eliom__client.js,v 1.1 2018/08/15 13:51:50 jaapb Exp $

Use caml_jsbytes (from upstream pull request #577)
--- src/lib/client/eliom_client.js.orig	2018-02-08 14:30:46.000000000 +0000
+++ src/lib/client/eliom_client.js
@@ -3,9 +3,9 @@
 //Provides: caml_unwrap_value_from_string mutable
 //Requires: caml_failwith, caml_marshal_constants
 //Requires: caml_int64_float_of_bits, caml_int64_of_bytes, caml_new_string
-//Requires: caml_bytes_of_string
+//Requires: caml_jsbytes_of_string
 var caml_unwrap_value_from_string = function (){
-  function StringReader (s, i) { this.s = caml_bytes_of_string(s); this.i = i; }
+  function StringReader (s, i) { this.s = caml_jsbytes_of_string(s); this.i = i; }
   StringReader.prototype = {
     read8u:function () { return this.s.charCodeAt(this.i++); },
     read8s:function () { return this.s.charCodeAt(this.i++) << 24 >> 24; },
