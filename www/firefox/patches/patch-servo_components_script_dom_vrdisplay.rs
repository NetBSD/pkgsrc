$NetBSD: patch-servo_components_script_dom_vrdisplay.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/script/dom/vrdisplay.rs.orig	2017-09-14 20:15:56.000000000 +0000
+++ servo/components/script/dom/vrdisplay.rs
@@ -268,7 +268,7 @@ impl VRDisplayMethods for VRDisplay {
     fn CancelAnimationFrame(&self, handle: u32) {
         if self.presenting.get() {
             let mut list = self.raf_callback_list.borrow_mut();
-            if let Some(mut pair) = list.iter_mut().find(|pair| pair.0 == handle) {
+            if let Some(pair) = list.iter_mut().find(|pair| pair.0 == handle) {
                 pair.1 = None;
             }
         } else {
