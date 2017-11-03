$NetBSD: patch-servo_components_style_gecko_wrapper.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/style/gecko/wrapper.rs.orig	2017-09-14 20:15:56.000000000 +0000
+++ servo/components/style/gecko/wrapper.rs
@@ -386,7 +386,12 @@ impl<'a> Iterator for GeckoChildrenItera
                 curr
             },
             GeckoChildrenIterator::GeckoIterator(ref mut it) => unsafe {
-                Gecko_GetNextStyleChild(it).map(GeckoNode)
+                // We do this unsafe lengthening of the lifetime here because
+                // structs::StyleChildrenIterator is actually StyleChildrenIterator<'a>,
+                // however we can't express this easily with bindgen, and it would
+                // introduce functions with two input lifetimes into bindgen,
+                // which would be out of scope for elision.
+                Gecko_GetNextStyleChild(&mut * (it as *mut _)).map(GeckoNode)
             }
         }
     }
@@ -424,7 +429,7 @@ impl<'lb> GeckoXBLBinding<'lb> {
         }
     }
 
-    fn each_xbl_stylist<F>(self, mut f: &mut F)
+    fn each_xbl_stylist<F>(self, f: &mut F)
     where
         F: FnMut(&Stylist),
     {
