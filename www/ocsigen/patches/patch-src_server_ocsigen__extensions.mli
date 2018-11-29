$NetBSD: patch-src_server_ocsigen__extensions.mli,v 1.1 2018/11/29 10:54:14 jaapb Exp $

Replace tyxml.parser with xml-light (patch from upstream)
--- src/server/ocsigen_extensions.mli.orig	2018-02-01 12:55:17.000000000 +0000
+++ src/server/ocsigen_extensions.mli
@@ -262,7 +262,7 @@ type extension = request_state -> answer
     the extension may want to modify the result (filters).
 *)
 
-type parse_fun = Simplexmlparser.xml list -> extension2
+type parse_fun = Xml.xml list -> extension2
 
 (** Type of the functions parsing the content of a <host> tag *)
 type parse_host
@@ -305,7 +305,7 @@ and parse_config_user =
   userconf_info -> parse_config
 and parse_config_aux =
     Url.path -> parse_host ->
-    (parse_fun -> Simplexmlparser.xml ->
+    (parse_fun -> Xml.xml ->
      extension
     )
 
@@ -355,7 +355,7 @@ val register_extension :
   ?user_fun_site:parse_config_user ->
   ?begin_init:(unit -> unit) ->
   ?end_init:(unit -> unit) ->
-  ?init_fun:(Simplexmlparser.xml list -> unit) ->
+  ?init_fun:(Xml.xml list -> unit) ->
   ?exn_handler:(exn -> string) ->
   ?respect_pipeline:bool ->
   unit -> unit
@@ -388,7 +388,7 @@ module Configuration : sig
     ?elements:element list ->
     ?attributes:attribute list ->
     ?pcdata:(string -> unit) ->
-    ?other_elements:(string -> (string * string) list -> Simplexmlparser.xml list -> unit) ->
+    ?other_elements:(string -> (string * string) list -> Xml.xml list -> unit) ->
     ?other_attributes:(string -> string -> unit) ->
     unit -> element
 
@@ -416,17 +416,17 @@ module Configuration : sig
     in_tag:string ->
     elements:element list ->
     ?pcdata:(string -> unit) ->
-    ?other_elements:(string -> (string * string) list -> Simplexmlparser.xml list -> unit) ->
-    Simplexmlparser.xml -> unit
+    ?other_elements:(string -> (string * string) list -> Xml.xml list -> unit) ->
+    Xml.xml -> unit
 
   (** Application of [process_element] on a list of XML elements. *)
   val process_elements :
     in_tag:string ->
     elements:element list ->
     ?pcdata:(string -> unit) ->
-    ?other_elements:(string -> (string * string) list -> Simplexmlparser.xml list -> unit) ->
+    ?other_elements:(string -> (string * string) list -> Xml.xml list -> unit) ->
     ?init:(unit -> unit) ->
-    Simplexmlparser.xml list -> unit
+    Xml.xml list -> unit
 
   (** The specification for ignoring blank PCDATA ('\n', '\r', ' ', '\t') and failing
       otherwise (a reasonable default). *)
@@ -524,7 +524,7 @@ val get_numberofreloads : unit -> int
 
 val get_init_exn_handler : unit -> exn -> string
 
-val set_config : Simplexmlparser.xml list -> unit
+val set_config : Xml.xml list -> unit
 
 val client_of_connection : Ocsigen_http_com.connection -> client
 
