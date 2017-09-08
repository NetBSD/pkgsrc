$NetBSD: patch-src_lib_eliom_request.client.ml,v 1.1 2017/09/08 17:14:34 jaapb Exp $

XmlHttpRequest changed
--- src/lib/eliom_request.client.ml.orig	2017-02-07 15:42:18.000000000 +0000
+++ src/lib/eliom_request.client.ml
@@ -24,6 +24,8 @@ exception Failed_request of int
 exception Program_terminated
 exception Non_xml_content
 
+module XmlHttpRequest = Js_of_ocaml_lwt.XmlHttpRequest
+
 let section = Lwt_log.Section.make "eliom:request"
 (* == ... *)
 
@@ -97,9 +99,6 @@ let redirect_post url params =
   (* firefox accepts submit only on forms in the document *)
   f##submit
 
-let redirect_post_form_elt ?(post_args=[]) ?(form_arg=[]) url =
-  redirect_post url (form_arg@post_args)
-
 (* Forms cannot use PUT http method: do not redirect *)
 let redirect_put _url _params =
   Lwt_log.raise_error ~section "redirect_put not implemented"
@@ -129,10 +128,10 @@ let nl_template_string = "__nl_n_eliom-t
 let send
     ?with_credentials
     ?(expecting_process_page = false) ?cookies_info
-    ?get_args ?post_args ?form_arg
+    ?get_args ?post_args
     ?progress ?upload_progress ?override_mime_type
     url result =
-  let rec aux i ?cookies_info ?(get_args=[]) ?post_args ?form_arg url =
+  let rec aux i ?cookies_info ?(get_args=[]) ?post_args url =
     let (https, path) = match cookies_info with
       | Some c -> c
       (* CCC Is it really necessary to allow to specify cookie_info here?
@@ -205,14 +204,6 @@ let send
       then (Eliom_common.nl_get_appl_parameter, "true")::get_args
       else get_args
     in
-    let form_contents =
-      match form_arg with
-        | None -> None
-        | Some form_arg ->
-          let contents = Form.empty_form_contents () in
-          List.iter (Form.append contents) form_arg;
-          Some contents
-    in
     let check_headers code headers =
       if expecting_process_page
       then
@@ -224,10 +215,18 @@ let send
       else true
     in
     try%lwt
-      let%lwt r = XmlHttpRequest.perform_raw_url
+      let%lwt r =
+        let contents =
+                match post_args with
+                | Some post_args ->
+                                Some (`POST_form post_args)
+                | None ->
+                                None
+        in
+        XmlHttpRequest.perform_raw_url
           ?with_credentials
           ?headers:(Some headers) ?content_type:None
-          ?post_args ~get_args ?form_arg:form_contents ~check_headers
+          ?contents ~get_args ~check_headers
           ?progress ?upload_progress ?override_mime_type url
       in
       (if Js.Unsafe.global##.___eliom_use_cookie_substitutes_ <> Js.undefined
@@ -255,9 +254,10 @@ let send
              with
                | None | Some "" -> Lwt.return (r.XmlHttpRequest.url, None)
                | Some uri ->
-                 (match post_args, form_arg with
-                   | None, None -> redirect_get uri
-                   | _, _ -> redirect_post_form_elt ?post_args ?form_arg url);
+                               redirect_post url
+                               (match post_args with
+                               | Some post_args -> post_args
+                               | None -> []);
                  Lwt.fail Program_terminated)
           | Some uri ->
             if i < max_redirection_level
@@ -288,9 +288,9 @@ let send
            us that the answer is not application content *)
         match headers Eliom_common.appl_name_header_name with
           | None | Some "" -> (* Empty appl_name for IE compat. *)
-            (match post_args, form_arg with
-              | None, None -> redirect_get url
-              | _, _ -> Lwt_log.raise_error ~section  "can't silently redirect a Post request to non application content");
+                          (match post_args with
+                          | None -> redirect_get url
+                          | _ -> Lwt_log.raise_error ~section "can't silently redirect a Post request to non application content");
             Lwt.fail Program_terminated
           | Some appl_name ->
             let current_appl_name = Eliom_process.get_application_name () in
@@ -305,7 +305,7 @@ let send
                 Lwt.fail (Failed_request code)
               end
   in
-  let%lwt (url, content) = aux 0 ?cookies_info ?get_args ?post_args ?form_arg url in
+  let%lwt (url, content) = aux 0 ?cookies_info ?get_args ?post_args url in
   let filter_url url =
     { url with Url.hu_arguments =
         List.filter (fun (e,_) -> e <> nl_template_string) url.Url.hu_arguments } in
@@ -341,7 +341,6 @@ let add_button_arg inj args form =
         else args
 (* END FORMDATA HACK *)
 
-
 (** Send a GET form with tab cookies and half/full XHR.
     If [~post_params] is present, the HTTP method will be POST,
     with form data in the URL.
@@ -368,12 +367,26 @@ let send_post_form
     ?progress ?upload_progress ?override_mime_type
     form url =
   (* BEGIN FORMDATA HACK *)
-  let post_args = add_button_arg (fun x -> `String x) post_args form in
+            let post_args =
+                    match
+                    add_button_arg (fun x -> `String x)
+                    (Some (Form.form_elements form))
+                    form,
+                    post_args
+                    with
+                    | Some l, Some l' ->
+                                    Some (l @ l')
+                    | Some l, _
+                    | _, Some l ->
+                                    Some l
+                    | None, None ->
+                                    None
+            in
   (* END FORMDATA HACK *)
   send ?with_credentials
     ?expecting_process_page ?cookies_info ?get_args ?post_args
     ?progress ?upload_progress ?override_mime_type
-    ~form_arg:(Form.form_elements form) url
+    url
 
 let http_get ?with_credentials ?expecting_process_page ?cookies_info
     ?progress ?upload_progress ?override_mime_type
