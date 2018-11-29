$NetBSD: patch-src_lib_eliom__config.server.mli,v 1.1 2018/11/29 12:04:23 jaapb Exp $

Use xml-light (patch from upstream)
--- src/lib/eliom_config.server.mli.orig	2018-02-08 14:30:46.000000000 +0000
+++ src/lib/eliom_config.server.mli
@@ -89,13 +89,13 @@ val get_default_links_xhr : unit -> bool
     function inside the initialisation function given to
     {!Eliom_service.register_eliom_module}.}
 *)
-val get_config : unit -> Simplexmlparser.xml list
+val get_config : unit -> Xml.xml list
 
 (** Process the configuration
     (same as the one returned by
     {% <<a_api module="Eliom_config" | val get_config>> %})
     by a given specification (cf. {% <<a_api project="ocsigenserver" | type Ocsigen_extensions.Configuration.element >> %}) *)
-val parse_config : ?pcdata:(string -> unit) -> ?other_elements:(string -> (string * string) list -> Simplexmlparser.xml list -> unit) -> Ocsigen_extensions.Configuration.element list -> unit
+val parse_config : ?pcdata:(string -> unit) -> ?other_elements:(string -> (string * string) list -> Xml.xml list -> unit) -> Ocsigen_extensions.Configuration.element list -> unit
 
 (** The function [get_config_info ()] returns the information
     concerning the current request from the configuration files
