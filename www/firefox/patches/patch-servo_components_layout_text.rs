$NetBSD: patch-servo_components_layout_text.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/layout/text.rs.orig	2017-09-14 20:15:56.000000000 +0000
+++ servo/components/layout/text.rs
@@ -460,7 +460,7 @@ fn split_first_fragment_at_newline_if_ne
     }
 
     let new_fragment = {
-        let mut first_fragment = fragments.front_mut().unwrap();
+        let first_fragment = fragments.front_mut().unwrap();
         let string_before;
         let selection_before;
         {
