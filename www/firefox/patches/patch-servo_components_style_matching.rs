$NetBSD: patch-servo_components_style_matching.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/style/matching.rs.orig	2017-09-14 20:15:57.000000000 +0000
+++ servo/components/style/matching.rs
@@ -440,7 +440,7 @@ pub trait MatchMethods : TElement {
     fn finish_restyle(
         &self,
         context: &mut StyleContext<Self>,
-        mut data: &mut ElementData,
+        data: &mut ElementData,
         mut new_styles: ElementStyles,
         important_rules_changed: bool,
     ) -> ChildCascadeRequirement {
