$NetBSD: patch-servo_components_style_stylesheets_rule__list.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/style/stylesheets/rule_list.rs.orig	2017-09-14 20:15:57.000000000 +0000
+++ servo/components/style/stylesheets/rule_list.rs
@@ -150,7 +150,7 @@ impl CssRulesHelpers for RawOffsetArc<Lo
 
         {
             let mut write_guard = lock.write();
-            let mut rules = self.write_with(&mut write_guard);
+            let rules = self.write_with(&mut write_guard);
             // Step 5
             // Computes the maximum allowed parser state at a given index.
             let rev_state = rules.0.get(index).map_or(State::Body, CssRule::rule_state);
