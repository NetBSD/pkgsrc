$NetBSD: patch-src_http_ocsigen_senders.mli,v 1.1 2016/06/20 19:35:56 jaapb Exp $

Catch up with Tyxml (patch from upstream, not in release yet)
--- src/http/ocsigen_senders.mli.orig	2016-04-12 12:46:24.000000000 +0000
+++ src/http/ocsigen_senders.mli
@@ -23,8 +23,8 @@ module File_content : Ocsigen_http_frame
   with  type t =
     string * Ocsigen_charset_mime.charset_assoc * Ocsigen_charset_mime.mime_assoc
 
-module Html5_content :
-  Ocsigen_http_frame.HTTP_CONTENT with type t = Html5.M.doc
+module Html_content :
+  Ocsigen_http_frame.HTTP_CONTENT with type t = Tyxml.Html.doc
 
 module Make_XML_Content(Xml : Xml_sigs.Iterable)
     (Typed_xml : Xml_sigs.Typed_xml with module Xml := Xml) :
