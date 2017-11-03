$NetBSD: patch-servo_components_layout_sequential.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/layout/sequential.rs.orig	2017-09-14 20:15:55.000000000 +0000
+++ servo/components/layout/sequential.rs
@@ -133,7 +133,7 @@ pub fn store_overflow(layout_context: &L
         return;
     }
 
-    for mut kid in flow::mut_base(flow).child_iter_mut() {
+    for kid in flow::mut_base(flow).child_iter_mut() {
         store_overflow(layout_context, kid);
     }
 
