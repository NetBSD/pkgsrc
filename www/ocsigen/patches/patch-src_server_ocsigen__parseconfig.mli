$NetBSD: patch-src_server_ocsigen__parseconfig.mli,v 1.1 2018/11/29 10:54:14 jaapb Exp $

Replace tyxml.parser with xml-light (patch from upstream)
--- src/server/ocsigen_parseconfig.mli.orig	2018-02-01 12:55:17.000000000 +0000
+++ src/server/ocsigen_parseconfig.mli
@@ -36,13 +36,13 @@ val parse_size_tag : string -> string ->
 (** Parse a string (PCDATA) as XML content.
     Raises [Failure "Ocsigen_parseconfig.parse_string"] in case of error.
 *)
-val parse_string : Simplexmlparser.xml list -> string
+val parse_string : Xml.xml list -> string
 
 (** [parse_string_tag tag s] parses a string (same syntax as [parse_string]).
     In case of error, raises [Ocsigen_config.Config_file_error m] where [m]
     is an error message explaining that a string was expected in tag [<tag>].
 *)
-val parse_string_tag : string -> Simplexmlparser.xml list -> string
+val parse_string_tag : string -> Xml.xml list -> string
 
 
 (** Parses the [hostfilter] field of the configuration file, which
@@ -52,9 +52,8 @@ val parse_host_field: string option -> O
 
 (**/**)
 
-val parser_config : Simplexmlparser.xml list ->
-  Simplexmlparser.xml list list
-val parse_server : bool -> Simplexmlparser.xml list -> unit
+val parser_config : Xml.xml -> Xml.xml list list
+val parse_server : bool -> Xml.xml list -> unit
 
 type ssl_info = {
   ssl_certificate : string option;
@@ -76,7 +75,7 @@ type ssl_info = {
     }
 *)
 val extract_info :
-  Simplexmlparser.xml list ->
+  Xml.xml list ->
   (string option * string option) *
   (ssl_info option *
    (Ocsigen_socket.socket_type * int) list *
@@ -86,4 +85,4 @@ val extract_info :
 val parse_config :
   ?file:string ->
   unit ->
-  Simplexmlparser.xml list list
+  Xml.xml list list
