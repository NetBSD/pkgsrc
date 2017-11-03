$NetBSD: patch-servo_components_style_properties_properties.mako.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/style/properties/properties.mako.rs.orig	2017-09-14 20:15:57.000000000 +0000
+++ servo/components/style/properties/properties.mako.rs
@@ -3364,7 +3364,7 @@ pub fn modify_border_style_for_inline_si
                 return;
             }
         }
-        let mut style = Arc::make_mut(style);
+        let style = Arc::make_mut(style);
         let border = Arc::make_mut(&mut style.border);
         match side {
             PhysicalSide::Left => {
