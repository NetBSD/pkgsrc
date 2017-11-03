$NetBSD: patch-servo_components_style_gecko_conversions.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/style/gecko/conversions.rs.orig	2017-09-14 20:15:56.000000000 +0000
+++ servo/components/style/gecko/conversions.rs
@@ -348,7 +348,7 @@ impl nsStyleImage {
             // NB: stops are guaranteed to be none in the gecko side by
             // default.
 
-            let mut gecko_stop = unsafe {
+            let gecko_stop = unsafe {
                 &mut (*gecko_gradient).mStops[index]
             };
             let mut coord = nsStyleCoord::null();
