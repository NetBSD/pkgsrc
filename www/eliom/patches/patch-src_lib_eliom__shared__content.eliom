$NetBSD: patch-src_lib_eliom__shared__content.eliom,v 1.1 2018/11/29 12:04:23 jaapb Exp $

Compile with tyxml 4.3.0
--- src/lib/eliom_shared_content.eliom.orig	2018-02-08 14:30:46.000000000 +0000
+++ src/lib/eliom_shared_content.eliom
@@ -68,6 +68,9 @@ module Xml = struct
   type keyboard_event_handler =
     (Dom_html.keyboardEvent Js.t -> unit) Eliom_client_value.t
 
+  type touch_event_handler =
+    (Dom_html.touchEvent Js.t -> unit) Eliom_client_value.t
+
   (* attributes *)
 
   type attrib = Eliom_content_core.Xml.attrib
@@ -127,6 +130,9 @@ module Xml = struct
   let keyboard_event_handler_attrib =
     Eliom_content_core.Xml.keyboard_event_handler_attrib
 
+  let touch_event_handler_attrib =
+    Eliom_content_core.Xml.touch_event_handler_attrib
+
   let mouse_event_handler_attrib =
     Eliom_content_core.Xml.mouse_event_handler_attrib
 
