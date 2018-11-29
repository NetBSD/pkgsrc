$NetBSD: patch-src_extensions_authbasic.mli,v 1.1 2018/11/29 10:54:14 jaapb Exp $

Replace tyxml.parser with xml-light (patch from upstream)
--- src/extensions/authbasic.mli.orig	2018-02-01 12:55:17.000000000 +0000
+++ src/extensions/authbasic.mli
@@ -34,7 +34,7 @@
 
 
 val register_basic_authentication_method :
-  (Simplexmlparser.xml -> string -> string -> bool Lwt.t) -> unit
+  (Xml.xml -> string -> string -> bool Lwt.t) -> unit
 (** This function registers an authentication plugin: it adds a new
     parser to the list of available authentication schemes.
 
@@ -55,7 +55,7 @@ val register_basic_authentication_method
 
 
 val get_basic_authentication_method :
-  Simplexmlparser.xml -> string -> string -> bool Lwt.t
+  Xml.xml -> string -> string -> bool Lwt.t
 (** This function combines all the parsers registered with
     [register_basic_authentication_method]. It might be useful for
     other extensions. Not for the casual user. *)
