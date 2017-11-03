$NetBSD: patch-servo_components_script_dom_url.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/script/dom/url.rs.orig	2017-07-31 16:20:53.000000000 +0000
+++ servo/components/script/dom/url.rs
@@ -96,8 +96,8 @@ impl URL {
 
     // https://w3c.github.io/FileAPI/#dfn-createObjectURL
     pub fn CreateObjectURL(global: &GlobalScope, blob: &Blob) -> DOMString {
-        /// XXX: Second field is an unicode-serialized Origin, it is a temporary workaround
-        ///      and should not be trusted. See issue https://github.com/servo/servo/issues/11722
+        // XXX: Second field is an unicode-serialized Origin, it is a temporary workaround
+        //      and should not be trusted. See issue https://github.com/servo/servo/issues/11722
         let origin = get_blob_origin(&global.get_url());
 
         let id = blob.get_blob_url_id();
