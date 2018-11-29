$NetBSD: patch-src_lib_eliom__content__core.client.mli,v 1.1 2018/11/29 12:04:23 jaapb Exp $

Compile with tyxml 4.3.0
--- src/lib/eliom_content_core.client.mli.orig	2018-02-08 14:30:46.000000000 +0000
+++ src/lib/eliom_content_core.client.mli
@@ -44,6 +44,8 @@ module Xml : sig
         (Dom_html.mouseEvent Js.t -> unit) (* Client side-only *)
     | CE_client_closure_keyboard of
         (Dom_html.keyboardEvent Js.t -> unit) (* Client side-only *)
+    | CE_client_closure_touch of
+        (Dom_html.touchEvent Js.t -> unit) (* Client side-only *)
     | CE_call_service of
         ( [ `A | `Form_get | `Form_post] *
           ((bool * string list) option) *
@@ -55,6 +57,7 @@ module Xml : sig
   type event_handler = Dom_html.event Js.t -> unit
   type mouse_event_handler = Dom_html.mouseEvent Js.t -> unit
   type keyboard_event_handler = Dom_html.keyboardEvent Js.t -> unit
+  type touch_event_handler = Dom_html.touchEvent Js.t -> unit
 
   type ename = string
   type elt
@@ -109,6 +112,7 @@ module Xml : sig
   val event_handler_attrib : aname -> event_handler -> attrib
   val mouse_event_handler_attrib : aname -> mouse_event_handler -> attrib
   val keyboard_event_handler_attrib : aname -> keyboard_event_handler -> attrib
+  val touch_event_handler_attrib : aname -> touch_event_handler -> attrib
   val uri_attrib : aname -> uri -> attrib
   val uris_attrib : aname -> uri list -> attrib
 
