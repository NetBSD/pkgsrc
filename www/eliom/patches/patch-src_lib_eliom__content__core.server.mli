$NetBSD: patch-src_lib_eliom__content__core.server.mli,v 1.1 2018/11/29 12:04:23 jaapb Exp $

Compile with tyxml 4.3.0
--- src/lib/eliom_content_core.server.mli.orig	2018-02-08 14:30:46.000000000 +0000
+++ src/lib/eliom_content_core.server.mli
@@ -30,6 +30,8 @@ module Xml : sig
            (Dom_html.mouseEvent Js.t -> unit) Eliom_client_value.t
      and type keyboard_event_handler =
            (Dom_html.keyboardEvent Js.t -> unit) Eliom_client_value.t
+     and type touch_event_handler =
+           (Dom_html.touchEvent Js.t -> unit) Eliom_client_value.t
 
   type caml_event_handler
 
