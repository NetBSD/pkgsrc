$NetBSD: patch-src_http_ocsigen_senders.ml,v 1.1 2016/06/20 19:35:56 jaapb Exp $

Catch up with Tyxml (patch from upstream, not in release yet)
--- src/http/ocsigen_senders.ml.orig	2016-04-12 12:46:24.000000000 +0000
+++ src/http/ocsigen_senders.ml
@@ -77,7 +77,7 @@ module Make_XML_Content(Xml : Xml_sigs.I
          ~stream:(x, None) ())
 end
 
-module Html5_content = Make_XML_Content(Xml)(Html5.M)
+module Html_content = Make_XML_Content(Tyxml.Xml)(Tyxml.Html)
 
 
 (*****************************************************************************)
@@ -473,11 +473,11 @@ struct
   let get_etag ?options c = None
 
   let error_page s msg c =
-    Html5.M.html
-      (Html5.M.head (Html5.M.title (Html5.M.pcdata s)) [])
-      (Html5.M.body
-         (Html5.M.h1 [Html5.M.pcdata msg]::
-          Html5.M.p [Html5.M.pcdata s]::
+    Tyxml.Html.html
+      (Tyxml.Html.head (Tyxml.Html.title (Tyxml.Html.pcdata s)) [])
+      (Tyxml.Html.body
+         (Tyxml.Html.h1 [Tyxml.Html.pcdata msg]::
+          Tyxml.Html.p [Tyxml.Html.pcdata s]::
           c)
       )
 
@@ -512,11 +512,11 @@ struct
         error_page
           ("Error "^str_code)
           error_msg
-          [Html5.M.p
-             [Html5.M.pcdata (Printexc.to_string exn);
-              Html5.M.br ();
-              Html5.M.em
-                [Html5.M.pcdata "(Ocsigen running in debug mode)"]
+          [Tyxml.Html.p
+             [Tyxml.Html.pcdata (Printexc.to_string exn);
+              Tyxml.Html.br ();
+              Tyxml.Html.em
+                [Tyxml.Html.pcdata "(Ocsigen running in debug mode)"]
              ]]
       | _ ->
         error_page
@@ -524,7 +524,7 @@ struct
           error_msg
           []
     in
-    Html5_content.result_of_content err_page >>= fun r ->
+    Html_content.result_of_content err_page >>= fun r ->
     Lwt.return
       (Result.update r
          ~cookies:cookies_to_set
