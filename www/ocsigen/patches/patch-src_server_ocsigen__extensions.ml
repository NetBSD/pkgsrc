$NetBSD: patch-src_server_ocsigen__extensions.ml,v 1.1 2018/11/29 10:54:14 jaapb Exp $

Replace tyxml.parser with xml-light (patch from upstream)
--- src/server/ocsigen_extensions.ml.orig	2018-02-01 12:55:17.000000000 +0000
+++ src/server/ocsigen_extensions.ml
@@ -291,13 +291,13 @@ and extension2 =
 type extension = request_state -> answer Lwt.t
 
 
-type parse_fun = Simplexmlparser.xml list -> extension2
+type parse_fun = Xml.xml list -> extension2
 
 
 type parse_host =
     Parse_host of
       (Url.path ->
-       parse_host -> parse_fun -> Simplexmlparser.xml -> extension)
+       parse_host -> parse_fun -> Xml.xml -> extension)
 
 let (hosts : (virtual_hosts * config_info * extension2) list ref) =
   ref []
@@ -357,7 +357,7 @@ let new_url_of_directory_request request
 
 (*****************************************************************************)
 (* To give parameters to extensions: *)
-let dynlinkconfig = ref ([] : Simplexmlparser.xml list)
+let dynlinkconfig = ref ([] : Xml.xml list)
 let set_config s = dynlinkconfig := s
 let get_config () = !dynlinkconfig
 
@@ -458,7 +458,7 @@ let rec default_parse_config
     prevpath
     (Parse_host parse_host)
     (parse_fun : parse_fun) = function
-  | Simplexmlparser.Element ("site", atts, l) ->
+  | Xml.Element ("site", atts, l) ->
     let rec parse_site_attrs (enc,dir) = function
       | [] -> (match dir with
           | None ->
@@ -550,7 +550,7 @@ let rec default_parse_config
             Lwt.return (Ext_found_continue_with' (r, ri))
         | Req_not_found (err, ri) ->
             Lwt.return (Ext_sub_result ext))
-  | Simplexmlparser.Element (tag,_,_) ->
+  | Xml.Element (tag,_,_) ->
     raise (Bad_config_tag_for_extension tag)
   | _ -> raise (Ocsigen_config.Config_file_error
                   ("Unexpected content inside <host>"))
@@ -613,7 +613,7 @@ type parse_config = virtual_hosts -> con
 and parse_config_user = userconf_info -> parse_config
 and parse_config_aux =
     Url.path -> parse_host ->
-    (parse_fun -> Simplexmlparser.xml ->
+    (parse_fun -> Xml.xml ->
      extension
     )
 
@@ -621,11 +621,11 @@ and parse_config_aux =
 
 let user_extension_void_fun_site : parse_config_user =
   fun _ _ _ _ _ _ -> function
-    | Simplexmlparser.Element (t, _, _) -> raise (Bad_config_tag_for_extension t)
+    | Xml.Element (t, _, _) -> raise (Bad_config_tag_for_extension t)
     | _ -> raise (Error_in_config_file "Unexpected data in config file")
 
 let extension_void_fun_site : parse_config = fun _ _ _ _ _ -> function
-  | Simplexmlparser.Element (t, _, _) -> raise (Bad_config_tag_for_extension t)
+  | Xml.Element (t, _, _) -> raise (Bad_config_tag_for_extension t)
   | _ -> raise (Error_in_config_file "Unexpected data in config file")
 
 
@@ -748,7 +748,7 @@ module Configuration = struct
     elements : element list;
     attributes : attribute list;
     pcdata : (string -> unit) option;
-    other_elements : (string -> (string * string) list -> Simplexmlparser.xml list -> unit) option;
+    other_elements : (string -> (string * string) list -> Xml.xml list -> unit) option;
     other_attributes : (string -> string -> unit) option;
   }
   and element = string * element'
@@ -792,7 +792,7 @@ module Configuration = struct
   let check_element_occurrence ~in_tag elements = function
     | name, { obligatory = true } ->
       let corresponding_element = function
-        | Simplexmlparser.Element (name', _, _) -> name = name'
+        | Xml.Element (name', _, _) -> name = name'
         | _ -> false
       in
       if not (List.exists corresponding_element elements) then
@@ -815,12 +815,12 @@ module Configuration = struct
   let rec process_element ~in_tag ~elements:spec_elements
       ?pcdata:spec_pcdata ?other_elements:spec_other_elements =
     function
-    | Simplexmlparser.PCData str ->
+    | Xml.PCData str ->
       let spec_pcdata =
         Option.get (fun () -> ignore_blank_pcdata ~in_tag) spec_pcdata
       in
       spec_pcdata str
-    | Simplexmlparser.Element (name, attributes, elements) ->
+    | Xml.Element (name, attributes, elements) ->
       try
         let spec = List.assoc name spec_elements in
         List.iter
