$NetBSD: patch-src_lib_server_eliommod.ml,v 1.1 2018/11/29 12:04:23 jaapb Exp $

Use xml-light (patch from upstream)
--- src/lib/server/eliommod.ml.orig	2018-02-08 14:30:46.000000000 +0000
+++ src/lib/server/eliommod.ml
@@ -216,7 +216,6 @@ Some !default_max_persistent_data_tab_se
 (****************************************************************************)
 (****************************************************************************)
 (****************************************************************************)
-open Simplexmlparser
 
 
 (* The following is common to global config and site config *)
@@ -316,20 +315,20 @@ let parse_eliom_option
     aux false false attrs
   in
  function
-  | (Element ("volatiletimeout", attrs, [])) ->
+  | (Xml.Element ("volatiletimeout", attrs, [])) ->
       let t, snoo, ct = parse_timeout_attrs "volatiletimeout" attrs in
       set_volatile_timeout ct snoo (t : float option)
-  | (Element ("datatimeout", attrs, [])) ->
+  | (Xml.Element ("datatimeout", attrs, [])) ->
       let t, snoo, ct = parse_timeout_attrs "datatimeout" attrs in
       set_data_timeout ct snoo t
-  | (Element ("servicetimeout", attrs, [])) ->
+  | (Xml.Element ("servicetimeout", attrs, [])) ->
       let t, snoo, ct = parse_timeout_attrs "servicetimeout" attrs in
       set_service_timeout ct snoo t
-  | (Element ("persistenttimeout", attrs, [])) ->
+  | (Xml.Element ("persistenttimeout", attrs, [])) ->
       let t, snoo, ct = parse_timeout_attrs "persistenttimeout" attrs in
       set_persistent_timeout ct snoo t
 
-  | (Element ("maxvolatilesessionspergroup", [("value", v)], [])) ->
+  | (Xml.Element ("maxvolatilesessionspergroup", [("value", v)], [])) ->
       (try
          let i = int_of_string v in
          set_max_service_sessions_per_group i;
@@ -338,21 +337,21 @@ let parse_eliom_option
          raise
            (Error_in_config_file
               ("Eliom: Wrong attribute value for maxvolatilesessionspergroup tag")))
-  | (Element ("maxservicesessionspergroup", [("value", v)], [])) ->
+  | (Xml.Element ("maxservicesessionspergroup", [("value", v)], [])) ->
       (try
          let i = int_of_string v in
          set_max_service_sessions_per_group i;
        with Failure _ ->
          raise (Error_in_config_file
                   ("Eliom: Wrong attribute value for maxservicesessionspergroup tag")))
-  | (Element ("maxdatasessionspergroup", [("value", v)], [])) ->
+  | (Xml.Element ("maxdatasessionspergroup", [("value", v)], [])) ->
       (try
          let i = int_of_string v in
          set_max_data_sessions_per_group i
        with Failure _ ->
          raise (Error_in_config_file
                   ("Eliom: Wrong attribute value for maxdatasessionspergroup tag")))
-  | (Element ("maxvolatilesessionspersubnet", [("value", v)], [])) ->
+  | (Xml.Element ("maxvolatilesessionspersubnet", [("value", v)], [])) ->
       (try
          let i = int_of_string v in
          set_max_service_sessions_per_subnet i;
@@ -360,21 +359,21 @@ let parse_eliom_option
        with Failure _ ->
          raise (Error_in_config_file
                   ("Eliom: Wrong attribute value for maxvolatilesessionspersubnet tag")))
-  | (Element ("maxservicesessionspersubnet", [("value", v)], [])) ->
+  | (Xml.Element ("maxservicesessionspersubnet", [("value", v)], [])) ->
       (try
          let i = int_of_string v in
          set_max_service_sessions_per_subnet i;
        with Failure _ ->
          raise (Error_in_config_file
                   ("Eliom: Wrong attribute value for maxservicesessionspersubnet tag")))
-  | (Element ("maxdatasessionspersubnet", [("value", v)], [])) ->
+  | (Xml.Element ("maxdatasessionspersubnet", [("value", v)], [])) ->
       (try
          let i = int_of_string v in
          set_max_data_sessions_per_subnet i
        with Failure _ ->
          raise (Error_in_config_file
                   ("Eliom: Wrong attribute value for maxdatasessionspersubnet tag")))
-  | (Element ("maxpersistentsessionspergroup", [("value", v)], [])) ->
+  | (Xml.Element ("maxpersistentsessionspergroup", [("value", v)], [])) ->
       (try
          let i = int_of_string v in
          set_max_persistent_sessions_per_group i;
@@ -382,7 +381,7 @@ let parse_eliom_option
          raise
            (Error_in_config_file
               ("Eliom: Wrong attribute value for maxpersistentsessionspergroup tag")))
-  | (Element ("maxvolatiletabsessionspergroup", [("value", v)], [])) ->
+  | (Xml.Element ("maxvolatiletabsessionspergroup", [("value", v)], [])) ->
       (try
          let i = int_of_string v in
          set_max_service_tab_sessions_per_group i;
@@ -391,21 +390,21 @@ let parse_eliom_option
          raise
            (Error_in_config_file
               ("Eliom: Wrong attribute value for maxvolatiletabsessionspergroup tag")))
-  | (Element ("maxservicetabsessionspergroup", [("value", v)], [])) ->
+  | (Xml.Element ("maxservicetabsessionspergroup", [("value", v)], [])) ->
       (try
          let i = int_of_string v in
          set_max_service_tab_sessions_per_group i;
        with Failure _ ->
          raise (Error_in_config_file
                   ("Eliom: Wrong attribute value for maxservicetabsessionspergroup tag")))
-  | (Element ("maxdatatabsessionspergroup", [("value", v)], [])) ->
+  | (Xml.Element ("maxdatatabsessionspergroup", [("value", v)], [])) ->
       (try
          let i = int_of_string v in
          set_max_data_tab_sessions_per_group i
        with Failure _ ->
          raise (Error_in_config_file
                   ("Eliom: Wrong attribute value for maxdatatabsessionspergroup tag")))
-  | (Element ("maxpersistenttabsessionspergroup", [("value", v)], [])) ->
+  | (Xml.Element ("maxpersistenttabsessionspergroup", [("value", v)], [])) ->
       (try
          let i = int_of_string v in
          set_max_persistent_tab_sessions_per_group i;
@@ -413,21 +412,21 @@ let parse_eliom_option
          raise
            (Error_in_config_file
               ("Eliom: Wrong attribute value for maxpersistenttabsessionspergroup tag")))
-  | (Element ("maxanonymouscoservicespersession", [("value", v)], [])) ->
+  | (Xml.Element ("maxanonymouscoservicespersession", [("value", v)], [])) ->
       (try
          let i = int_of_string v in
          set_max_services_per_session i;
        with Failure _ ->
          raise (Error_in_config_file
                   ("Eliom: Wrong attribute value for maxanonymouscoservicespersession tag")))
-  | (Element ("maxanonymouscoservicespersubnet", [("value", v)], [])) ->
+  | (Xml.Element ("maxanonymouscoservicespersubnet", [("value", v)], [])) ->
       (try
          let i = int_of_string v in
          set_max_services_per_subnet i;
        with Failure _ ->
          raise (Error_in_config_file
                   ("Eliom: Wrong attribute value for maxanonymouscoservicespersubnet tag")))
-  | (Element ("maxvolatilegroupspersite", [("value", v)], [])) ->
+  | (Xml.Element ("maxvolatilegroupspersite", [("value", v)], [])) ->
       (try
          let i = int_of_string v in
          set_max_volatile_groups_per_site i
@@ -435,7 +434,7 @@ let parse_eliom_option
          raise (Error_in_config_file
                   ("Eliom: Wrong attribute value for maxvolatilegroupspersite tag")))
 
-  | (Element ("securecookies", [("value", v)], [])) ->
+  | (Xml.Element ("securecookies", [("value", v)], [])) ->
       (try
          let i = match v with
            | "true" -> true
@@ -447,14 +446,14 @@ let parse_eliom_option
          raise (Error_in_config_file
                   ("Eliom: Wrong attribute value for securecookies tag")))
 
-  | (Element ("ipv4subnetmask", [("value", v)], [])) ->
+  | (Xml.Element ("ipv4subnetmask", [("value", v)], [])) ->
       (try
          let mask = int_of_string v in
          set_ipv4mask mask
        with _ ->
          raise (Error_in_config_file
                   ("Eliom: Wrong attribute value for ipv4subnetmask tag")))
-  | (Element ("ipv6subnetmask", [("value", v)], [])) ->
+  | (Xml.Element ("ipv6subnetmask", [("value", v)], [])) ->
       (try
          let mask = int_of_string v in
          set_ipv6mask mask
@@ -462,10 +461,10 @@ let parse_eliom_option
          raise (Error_in_config_file
                   ("Eliom: Wrong attribute value for ipv6subnetmask tag")))
 
-  | (Element ("applicationscript", attrs, [])) ->
+  | (Xml.Element ("applicationscript", attrs, [])) ->
       set_application_script (parse_application_script_attrs attrs)
 
-  | (Element (s, _, _)) ->
+  | (Xml.Element (s, _, _)) ->
       raise (Error_in_config_file
                ("Unexpected content <"^s^"> inside eliom config"))
   | _ -> raise (Error_in_config_file ("Unexpected content inside eliom config"))
@@ -487,7 +486,7 @@ let parse_eliom_options f l =
 
 let rec parse_global_config = function
   | [] -> ()
-  | (Element ("sessiongcfrequency", [("value", s)], p))::ll ->
+  | (Xml.Element ("sessiongcfrequency", [("value", s)], p))::ll ->
       (try
         let t = float_of_string s in
         Eliommod_gc.set_servicesessiongcfrequency (Some t);
@@ -501,7 +500,7 @@ let rec parse_global_config = function
         else raise (Error_in_config_file
                       "Eliom: Wrong value for <sessiongcfrequency>"));
       parse_global_config ll
-  | (Element ("servicesessiongcfrequency", [("value", s)], p))::ll ->
+  | (Xml.Element ("servicesessiongcfrequency", [("value", s)], p))::ll ->
       (try
         Eliommod_gc.set_servicesessiongcfrequency (Some (float_of_string s))
       with Failure _ ->
@@ -510,7 +509,7 @@ let rec parse_global_config = function
         else raise (Error_in_config_file
                       "Eliom: Wrong value for <servicesessiongcfrequency>"));
       parse_global_config ll
-  | (Element ("datasessiongcfrequency", [("value", s)], p))::ll ->
+  | (Xml.Element ("datasessiongcfrequency", [("value", s)], p))::ll ->
       (try
         Eliommod_gc.set_datasessiongcfrequency (Some (float_of_string s))
       with Failure _ ->
@@ -519,7 +518,7 @@ let rec parse_global_config = function
         else raise (Error_in_config_file
                       "Eliom: Wrong value for <datasessiongcfrequency>"));
       parse_global_config ll
-  | (Element ("persistentsessiongcfrequency",
+  | (Xml.Element ("persistentsessiongcfrequency",
               [("value", s)], p))::ll ->
                 (try
                   Eliommod_gc.set_persistentsessiongcfrequency
@@ -762,7 +761,7 @@ let parse_config hostpattern conf_info s
         raise
           (Error_in_config_file ("Wrong attribute for <eliom>: "^s))
   in fun _ parse_site -> function
-    | Element ("eliommodule", atts, content) ->
+    | Xml.Element ("eliommodule", atts, content) ->
       Eliom_extension.register_eliom_extension
         default_module_action;
       (match parse_module_attrs None atts with
@@ -776,7 +775,7 @@ let parse_config hostpattern conf_info s
         (Some (Eliom_extension.get_eliom_extension ()))
         sitedata
       else gen_nothing ()
-    | Element ("eliom", atts, content) ->
+    | Xml.Element ("eliom", atts, content) ->
 (*--- if we put the line "new_sitedata" here, then there is
   one service table for each <eliom> tag ...
   I think the other one is the best,
@@ -916,7 +915,7 @@ let parse_config hostpattern conf_info s
           eliommodulewarningdisplayed := true;
           gen_nothing ()
         end
-    | Element (t, _, _) ->
+    | Xml.Element (t, _, _) ->
         raise (Ocsigen_extensions.Bad_config_tag_for_extension t)
     | _ -> raise (Error_in_config_file "(Eliommod extension)")
 
