$NetBSD: patch-src_lib_eliom__client.client.ml,v 1.1 2018/04/13 13:17:34 jaapb Exp $

The >> syntax has been removed in Lwt 4.0.0.
--- src/lib/eliom_client.client.ml.orig	2018-02-08 14:30:46.000000000 +0000
+++ src/lib/eliom_client.client.ml
@@ -1305,8 +1305,8 @@ let () =
                     uri [(Eliom_request.nl_template_string, t)]
                     Eliom_request.string_result
                 in
-                set_template_content ~replace:true ~uri content >>
-                (scroll_to_fragment ~offset:state.position fragment;
+                set_template_content ~replace:true ~uri content >>=
+                fun () -> (scroll_to_fragment ~offset:state.position fragment;
                  Lwt.return_unit)
               | _ ->
                 with_new_page
