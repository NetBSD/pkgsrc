$NetBSD: patch-servo_components_style_gecko__bindings_sugar_ns__t__array.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/style/gecko_bindings/sugar/ns_t_array.rs.orig	2017-06-15 20:51:56.000000000 +0000
+++ servo/components/style/gecko_bindings/sugar/ns_t_array.rs
@@ -90,7 +90,7 @@ impl<T> nsTArray<T> {
         // this can leak
         debug_assert!(len >= self.len() as u32);
         self.ensure_capacity(len as usize);
-        let mut header = self.header_mut();
+        let header = self.header_mut();
         header.mLength = len;
     }
 
@@ -99,7 +99,7 @@ impl<T> nsTArray<T> {
     /// This will not leak since it only works on POD types (and thus doesn't assert)
     pub unsafe fn set_len_pod(&mut self, len: u32) where T: Copy {
         self.ensure_capacity(len as usize);
-        let mut header = unsafe { self.header_mut() };
+        let header = unsafe { self.header_mut() };
         header.mLength = len;
     }
 }
