$NetBSD: patch-src_lib_eliom__content__core.client.mk,v 1.1 2018/11/29 12:04:23 jaapb Exp $

Compile with tyxml 4.3.0
--- src/lib/eliom_content_core.client.ml.orig	2018-02-08 14:30:46.000000000 +0000
+++ src/lib/eliom_content_core.client.ml
@@ -90,6 +90,7 @@ module Xml = struct
   type event_handler = Dom_html.event Js.t -> unit
   type mouse_event_handler = Dom_html.mouseEvent Js.t -> unit
   type keyboard_event_handler = Dom_html.keyboardEvent Js.t -> unit
+  type touch_event_handler = Dom_html.touchEvent Js.t -> unit
 
   let event_handler_attrib name (value : event_handler) =
     internal_event_handler_attrib name
@@ -100,6 +101,9 @@ module Xml = struct
   let keyboard_event_handler_attrib name (value : keyboard_event_handler) =
     internal_event_handler_attrib name
       (Caml (CE_client_closure_keyboard value))
+  let touch_event_handler_attrib name (value : touch_event_handler) =
+    internal_event_handler_attrib name
+      (Caml (CE_client_closure_touch value))
 
   let node_react_children ?(a = []) name children =
     {elt = Lazy.from_val (ReactChildren (Node (name,a,[]),children)); node_id=NoId}
@@ -183,6 +187,7 @@ struct
   type event_handler = Xml.event_handler
   type mouse_event_handler = Xml.mouse_event_handler
   type keyboard_event_handler = Xml.keyboard_event_handler
+  type touch_event_handler = Xml.touch_event_handler
   type attrib = Xml.attrib
 
   let float_attrib name s : attrib =
@@ -198,6 +203,7 @@ struct
   let event_handler_attrib = Xml.event_handler_attrib
   let mouse_event_handler_attrib = Xml.mouse_event_handler_attrib
   let keyboard_event_handler_attrib = Xml.keyboard_event_handler_attrib
+  let touch_event_handler_attrib = Xml.touch_event_handler_attrib
   let uri_attrib name value =
     name, Xml.RAReact (React.S.map
                          (fun f -> Some (Xml.AStr (Eliom_lazy.force f))) value)
