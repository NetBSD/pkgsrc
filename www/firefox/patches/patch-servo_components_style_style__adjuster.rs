$NetBSD: patch-servo_components_style_style__adjuster.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/style/style_adjuster.rs.orig	2017-09-14 20:15:57.000000000 +0000
+++ servo/components/style/style_adjuster.rs
@@ -167,7 +167,7 @@ impl<'a, 'b: 'a> StyleAdjuster<'a, 'b> {
         // When 'contain: paint', update overflow from 'visible' to 'clip'.
         if self.style.get_box().clone_contain().contains(contain::PAINT) {
             if self.style.get_box().clone_overflow_x() == overflow::visible {
-                let mut box_style = self.style.mutate_box();
+                let box_style = self.style.mutate_box();
                 box_style.set_overflow_x(overflow::_moz_hidden_unscrollable);
                 box_style.set_overflow_y(overflow::_moz_hidden_unscrollable);
             }
@@ -182,7 +182,7 @@ impl<'a, 'b: 'a> StyleAdjuster<'a, 'b> {
         use properties::longhands::font_style::computed_value::T as font_style;
         use properties::longhands::font_weight::computed_value::T as font_weight;
         if self.style.get_font().clone__moz_math_variant() != moz_math_variant::none {
-            let mut font_style = self.style.mutate_font();
+            let font_style = self.style.mutate_font();
             // Sadly we don't have a nice name for the computed value
             // of "font-weight: normal".
             font_style.set_font_weight(font_weight::normal());
@@ -269,7 +269,7 @@ impl<'a, 'b: 'a> StyleAdjuster<'a, 'b> {
 
         if overflow_x != original_overflow_x ||
            overflow_y != original_overflow_y {
-            let mut box_style = self.style.mutate_box();
+            let box_style = self.style.mutate_box();
             box_style.set_overflow_x(overflow_x);
             box_style.set_overflow_y(overflow_y);
         }
