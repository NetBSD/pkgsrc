$NetBSD: patch-servo_components_style_stylesheets_rules__iterator.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/style/stylesheets/rules_iterator.rs.orig	2017-09-14 20:15:57.000000000 +0000
+++ servo/components/style/stylesheets/rules_iterator.rs
@@ -70,7 +70,7 @@ impl<'a, 'b, C> Iterator for RulesIterat
 
             let rule;
             let sub_iter = {
-                let mut nested_iter = self.stack.last_mut().unwrap();
+                let nested_iter = self.stack.last_mut().unwrap();
                 rule = match nested_iter.next() {
                     Some(r) => r,
                     None => {
