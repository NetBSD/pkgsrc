$NetBSD: patch-src_lib_eliom__content__core.server.ml,v 1.1 2018/11/29 12:04:23 jaapb Exp $

Compile with tyxml 4.3.0
--- src/lib/eliom_content_core.server.ml.orig	2018-02-08 14:30:46.000000000 +0000
+++ src/lib/eliom_content_core.server.ml
@@ -118,6 +118,7 @@ module Xml = struct
   type event_handler = (Dom_html.event Js.t -> unit) Eliom_client_value.t
   type mouse_event_handler = (Dom_html.mouseEvent Js.t -> unit) Eliom_client_value.t
   type keyboard_event_handler = (Dom_html.keyboardEvent Js.t -> unit) Eliom_client_value.t
+  type touch_event_handler = (Dom_html.touchEvent Js.t -> unit) Eliom_client_value.t
 
   let make_cryptographic_safe_string () =
     (* FIX: we should directly produce a string of the right length *)
@@ -138,6 +139,8 @@ module Xml = struct
     biggest_event_handler_attrib name cf
   let keyboard_event_handler_attrib name (cf : keyboard_event_handler) =
     biggest_event_handler_attrib name cf
+  let touch_event_handler_attrib name (cf : touch_event_handler) =
+    biggest_event_handler_attrib name cf
 
   let client_attrib ?init (x : attrib Eliom_client_value.t) =
     let crypto = make_cryptographic_safe_string () in
