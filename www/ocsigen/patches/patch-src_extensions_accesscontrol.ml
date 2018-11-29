$NetBSD: patch-src_extensions_accesscontrol.ml,v 1.1 2018/11/29 10:54:14 jaapb Exp $

Replace tyxml.parser with xml-light (patch from upstream)
--- src/extensions/accesscontrol.ml.orig	2018-02-01 12:55:17.000000000 +0000
+++ src/extensions/accesscontrol.ml
@@ -32,7 +32,6 @@ open Ocsigen_lib
 open Printf
 open Lwt
 open Ocsigen_extensions
-open Simplexmlparser
 open Ocsigen_http_frame
 
 
@@ -43,7 +42,7 @@ let section = Lwt_log.Section.make "ocsi
 
 let rec parse_condition = function
 
-    | Element ("ip", ["value", s], []) ->
+    | Xml.Element ("ip", ["value", s], []) ->
         let prefix =
           try
             Ipaddr.Prefix.of_string_exn s
@@ -67,9 +66,9 @@ let rec parse_condition = function
                "IP: %a does not match %s"
                (fun () -> Ocsigen_request_info.remote_ip) ri s;
            r)
-    | Element ("ip" as s, _, _) -> badconfig "Bad syntax for tag %s" s
+    | Xml.Element ("ip" as s, _, _) -> badconfig "Bad syntax for tag %s" s
 
-    | Element ("port", ["value", s], []) ->
+    | Xml.Element ("port", ["value", s], []) ->
         let port =
           try
             int_of_string s
@@ -87,9 +86,9 @@ let rec parse_condition = function
                (fun () ri -> string_of_int (Ocsigen_request_info.server_port ri))
                ri port;
            r)
-    | Element ("port" as s, _, _) -> badconfig "Bad syntax for tag %s" s
+    | Xml.Element ("port" as s, _, _) -> badconfig "Bad syntax for tag %s" s
 
-    | Element ("ssl", [], []) ->
+    | Xml.Element ("ssl", [], []) ->
         (fun ri ->
            let r = Ocsigen_request_info.ssl ri in
            if r then
@@ -97,9 +96,9 @@ let rec parse_condition = function
            else
              Lwt_log.ign_info ~section "SSL: not accepted";
            r)
-    | Element ("ssl" as s, _, _) -> badconfig "Bad syntax for tag %s" s
+    | Xml.Element ("ssl" as s, _, _) -> badconfig "Bad syntax for tag %s" s
 
-    | Element ("header", ["name", name; "regexp", reg], []) ->
+    | Xml.Element ("header", ["name", name; "regexp", reg], []) ->
         let regexp =
           try
             Netstring_pcre.regexp ("^"^reg^"$")
@@ -126,9 +125,9 @@ let rec parse_condition = function
            if not r
            then Lwt_log.ign_info_f "HEADER: header %s does not match %S" name reg;
            r)
-    | Element ("header" as s, _, _) -> badconfig "Bad syntax for tag %s" s
+    | Xml.Element ("header" as s, _, _) -> badconfig "Bad syntax for tag %s" s
 
-    | Element ("method", ["value", s], []) ->
+    | Xml.Element ("method", ["value", s], []) ->
         let meth =
           try
             Framepp.method_of_string s
@@ -146,9 +145,9 @@ let rec parse_condition = function
                "METHOD: %a does not match %s"
               (fun () ri -> Framepp.string_of_method (Ocsigen_request_info.meth ri)) ri s;
            r)
-    | Element ("method" as s, _, _) -> badconfig "Bad syntax for tag %s" s
+    | Xml.Element ("method" as s, _, _) -> badconfig "Bad syntax for tag %s" s
 
-    | Element ("protocol", ["value", s], []) ->
+    | Xml.Element ("protocol", ["value", s], []) ->
         let pr =
           try
             Framepp.proto_of_string s
@@ -166,9 +165,9 @@ let rec parse_condition = function
                "PROTOCOL: %a does not match %s"
                (fun () ri -> Framepp.string_of_proto (Ocsigen_request_info.protocol ri)) ri s;
            r)
-    | Element ("protocol" as s, _, _) -> badconfig "Bad syntax for tag %s" s
+    | Xml.Element ("protocol" as s, _, _) -> badconfig "Bad syntax for tag %s" s
 
-    | Element ("path", ["regexp", s], []) ->
+    | Xml.Element ("path", ["regexp", s], []) ->
         let regexp =
           try
             Netstring_pcre.regexp ("^"^s^"$")
@@ -189,22 +188,22 @@ let rec parse_condition = function
                "PATH: \"%a\" does not match %S"
                (fun () ri -> Ocsigen_request_info.sub_path_string ri) ri s;
            r)
-    | Element ("path" as s, _, _) -> badconfig "Bad syntax for tag %s" s
+    | Xml.Element ("path" as s, _, _) -> badconfig "Bad syntax for tag %s" s
 
-    | Element ("and", [], sub) ->
+    | Xml.Element ("and", [], sub) ->
         let sub = List.map parse_condition sub in
         (fun ri -> List.for_all (fun cond -> cond ri) sub)
-    | Element ("and" as s, _, _) -> badconfig "Bad syntax for tag %s" s
+    | Xml.Element ("and" as s, _, _) -> badconfig "Bad syntax for tag %s" s
 
-    | Element ("or", [], sub) ->
+    | Xml.Element ("or", [], sub) ->
         let sub = List.map parse_condition sub in
         (fun ri -> List.exists (fun cond -> cond ri) sub)
-    | Element ("or" as s, _, _) -> badconfig "Bad syntax for tag %s" s
+    | Xml.Element ("or" as s, _, _) -> badconfig "Bad syntax for tag %s" s
 
-    | Element ("not", [], [sub]) ->
+    | Xml.Element ("not", [], [sub]) ->
         let sub = parse_condition sub in
         (fun ri -> not (sub ri))
-    | Element ("not" as s, _, _) -> badconfig "Bad syntax for tag %s" s
+    | Xml.Element ("not" as s, _, _) -> badconfig "Bad syntax for tag %s" s
 
     | _ ->
         badconfig "Bad syntax for condition"
@@ -217,17 +216,17 @@ let comma_space_regexp = Netstring_pcre.
 
 let parse_config parse_fun = function
 
-  | Element ("if", [], sub) ->
+  | Xml.Element ("if", [], sub) ->
       let (condition, sub) = match sub with
         | cond::q -> (parse_condition cond, q)
         | _ -> badconfig "Bad condition in <if>"
       in
       let (ithen, sub) = match sub with
-          | Element("then", [], ithen)::q -> (parse_fun ithen, q)
+          | Xml.Element("then", [], ithen)::q -> (parse_fun ithen, q)
           | _ -> badconfig "Bad <then> branch in <if>"
       in
       let (ielse, sub) = match sub with
-          | Element ("else", [], ielse)::([] as q) -> (parse_fun ielse, q)
+          | Xml.Element ("else", [], ielse)::([] as q) -> (parse_fun ielse, q)
           | [] -> (parse_fun [], [])
           | _ -> badconfig "Bad <else> branch in <if>"
       in
@@ -243,17 +242,17 @@ let parse_config parse_fun = function
                  Lwt_log.ign_info ~section "COND: going into <else> branch, if any";
                  Ocsigen_extensions.Ext_sub_result ielse
                end))
-  | Element ("if" as s, _, _) -> badconfig "Bad syntax for tag %s" s
+  | Xml.Element ("if" as s, _, _) -> badconfig "Bad syntax for tag %s" s
 
 
-  | Element ("notfound", [], []) ->
+  | Xml.Element ("notfound", [], []) ->
       (fun rs ->
         Lwt_log.ign_info ~section "NOT_FOUND: taking in charge 404";
          Lwt.return (Ocsigen_extensions.Ext_stop_all
                        (Ocsigen_cookies.Cookies.empty, 404)))
-  | Element ("notfound" as s, _, _) -> badconfig "Bad syntax for tag %s" s
+  | Xml.Element ("notfound" as s, _, _) -> badconfig "Bad syntax for tag %s" s
 
-  | Element ("nextsite", [], []) ->
+  | Xml.Element ("nextsite", [], []) ->
       (function
          | Ocsigen_extensions.Req_found (_, r) ->
              Lwt.return (Ocsigen_extensions.Ext_found_stop
@@ -262,7 +261,7 @@ let parse_config parse_fun = function
              Lwt.return (Ocsigen_extensions.Ext_stop_site
                            (Ocsigen_cookies.Cookies.empty, 404)))
 
-  | Element ("nexthost", [], []) ->
+  | Xml.Element ("nexthost", [], []) ->
       (function
          | Ocsigen_extensions.Req_found (_, r) ->
              Lwt.return (Ocsigen_extensions.Ext_found_stop
@@ -270,9 +269,9 @@ let parse_config parse_fun = function
          | Ocsigen_extensions.Req_not_found (err, ri) ->
              Lwt.return (Ocsigen_extensions.Ext_stop_host
                            (Ocsigen_cookies.Cookies.empty, 404)))
-  | Element ("nextsite" as s, _, _) -> badconfig "Bad syntax for tag %s" s
+  | Xml.Element ("nextsite" as s, _, _) -> badconfig "Bad syntax for tag %s" s
 
-  | Element ("stop", [], []) ->
+  | Xml.Element ("stop", [], []) ->
       (function
          | Ocsigen_extensions.Req_found (_, r) ->
              Lwt.return (Ocsigen_extensions.Ext_found_stop
@@ -280,25 +279,25 @@ let parse_config parse_fun = function
          | Ocsigen_extensions.Req_not_found (err, ri) ->
              Lwt.return (Ocsigen_extensions.Ext_stop_all
                            (Ocsigen_cookies.Cookies.empty, 404)))
-  | Element ("stop" as s, _, _) -> badconfig "Bad syntax for tag %s" s
+  | Xml.Element ("stop" as s, _, _) -> badconfig "Bad syntax for tag %s" s
 
-  | Element ("forbidden", [], []) ->
+  | Xml.Element ("forbidden", [], []) ->
     (fun rs ->
        Lwt_log.ign_info ~section "FORBIDDEN: taking in charge 403";
          Lwt.return (Ocsigen_extensions.Ext_stop_all
                        (Ocsigen_cookies.Cookies.empty, 403)))
-  | Element ("forbidden" as s, _, _) -> badconfig "Bad syntax for tag %s" s
+  | Xml.Element ("forbidden" as s, _, _) -> badconfig "Bad syntax for tag %s" s
 
-  | Element ("iffound", [], sub) ->
+  | Xml.Element ("iffound", [], sub) ->
       let ext = parse_fun sub in
       (function
          | Ocsigen_extensions.Req_found (_, _) ->
              Lwt.return (Ext_sub_result ext)
          | Ocsigen_extensions.Req_not_found (err, ri) ->
              Lwt.return (Ocsigen_extensions.Ext_next err))
-  | Element ("iffound" as s, _, _) -> badconfig "Bad syntax for tag %s" s
+  | Xml.Element ("iffound" as s, _, _) -> badconfig "Bad syntax for tag %s" s
 
-  | Element ("ifnotfound", [], sub) ->
+  | Xml.Element ("ifnotfound", [], sub) ->
       let ext = parse_fun sub in
       (function
          | Ocsigen_extensions.Req_found (_, r) ->
@@ -306,7 +305,7 @@ let parse_config parse_fun = function
                            (fun () -> Lwt.return r))
          | Ocsigen_extensions.Req_not_found (err, ri) ->
              Lwt.return (Ext_sub_result ext))
-  | Element ("ifnotfound", [("code", s)], sub) ->
+  | Xml.Element ("ifnotfound", [("code", s)], sub) ->
       let ext = parse_fun sub in
       let r = Netstring_pcre.regexp ("^"^s^"$") in
       (function
@@ -318,9 +317,9 @@ let parse_config parse_fun = function
                Lwt.return (Ext_sub_result ext)
              else
                Lwt.return (Ocsigen_extensions.Ext_next err))
-  | Element ("ifnotfound" as s, _, _) -> badconfig "Bad syntax for tag %s" s
+  | Xml.Element ("ifnotfound" as s, _, _) -> badconfig "Bad syntax for tag %s" s
 
-  | Element ("allow-forward-for", param, _) ->
+  | Xml.Element ("allow-forward-for", param, _) ->
     let apply request code =
       Lwt_log.ign_info ~section "Allowed proxy";
       let request =
@@ -372,7 +371,7 @@ let parse_config parse_fun = function
         apply request (Ocsigen_http_frame.Result.code resp)
       | Ocsigen_extensions.Req_not_found (code, request) -> apply request code)
 
-  | Element ("allow-forward-proto", _, _) ->
+  | Xml.Element ("allow-forward-proto", _, _) ->
     let apply request code =
       Lwt_log.ign_info ~section "Allowed proxy for ssl";
       let request =
@@ -406,7 +405,7 @@ let parse_config parse_fun = function
       | Ocsigen_extensions.Req_found (request, resp) ->
         apply request (Ocsigen_http_frame.Result.code resp)
       | Ocsigen_extensions.Req_not_found (code, request) -> apply request code)
-  | Element (t, _, _) -> raise (Bad_config_tag_for_extension t)
+  | Xml.Element (t, _, _) -> raise (Bad_config_tag_for_extension t)
   | _ -> badconfig "(accesscontrol extension) Bad data"
 
 
