$NetBSD: patch-servo_components_script_dom_xmlhttprequest.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/script/dom/xmlhttprequest.rs.orig	2017-09-14 20:15:56.000000000 +0000
+++ servo/components/script/dom/xmlhttprequest.rs
@@ -627,7 +627,7 @@ impl XMLHttpRequestMethods for XMLHttpRe
 
                 if !content_type_set {
                     let ct = request.headers.get_mut::<ContentType>();
-                    if let Some(mut ct) = ct {
+                    if let Some(ct) = ct {
                         if let Some(encoding) = encoding {
                             for param in &mut (ct.0).2 {
                                 if param.0 == MimeAttr::Charset {
