$NetBSD: patch-src_extensions_authbasic.ml,v 1.1 2018/11/29 10:54:14 jaapb Exp $

Replace tyxml.parser with xml-light (patch from upstream)
--- src/extensions/authbasic.ml.orig	2018-02-01 12:55:17.000000000 +0000
+++ src/extensions/authbasic.ml
@@ -55,7 +55,7 @@ let register_basic_authentication_method
 (* Basic authentication with a predefined login/password (example) *)
 
 let _ =
-  let open Simplexmlparser in
+  let open Xml in
   register_basic_authentication_method
     (function
       | Element ("plain", ["login", login; "password", password], _) ->
@@ -133,7 +133,7 @@ let parse_config element =
           ]
           ~other_elements:(fun name attrs content ->
             rest_ref :=
-              Simplexmlparser.Element (name, attrs, content) :: !rest_ref)
+              Xml.Element (name, attrs, content) :: !rest_ref)
       ()]
       element
   );
