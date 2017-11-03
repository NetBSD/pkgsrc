$NetBSD: patch-servo_components_script_dom_webglrenderingcontext.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/script/dom/webglrenderingcontext.rs.orig	2017-09-14 20:15:56.000000000 +0000
+++ servo/components/script/dom/webglrenderingcontext.rs
@@ -2434,7 +2434,7 @@ impl WebGLRenderingContextMethods for We
         }
 
         typedarray!(in(cx) let mut pixels_data: ArrayBufferView = pixels);
-        let (array_type, mut data) = match { pixels_data.as_mut() } {
+        let (array_type, data) = match { pixels_data.as_mut() } {
             Ok(data) => (data.get_array_type(), data.as_mut_slice()),
             Err(_) => return Err(Error::Type("Not an ArrayBufferView".to_owned())),
         };
