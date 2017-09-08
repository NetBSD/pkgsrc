$NetBSD: patch-src_lib_eliom_request.client.mli,v 1.1 2017/09/08 17:14:34 jaapb Exp $

XmlHttpRequest changed
--- src/lib/eliom_request.client.mli.orig	2017-02-07 15:42:18.000000000 +0000
+++ src/lib/eliom_request.client.mli
@@ -38,7 +38,6 @@ val send :
   ?cookies_info:bool * string list ->
   ?get_args:(string * string) list ->
   ?post_args:(string * Eliommod_parameters.param) list ->
-  ?form_arg:((string * Form.form_elt) list) ->
   ?progress:(int -> int -> unit) ->
   ?upload_progress:(int -> int -> unit) ->
   ?override_mime_type:string ->
