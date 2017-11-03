$NetBSD: patch-servo_components_style_invalidation_element_invalidator.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/style/invalidation/element/invalidator.rs.orig	2017-09-14 20:15:57.000000000 +0000
+++ servo/components/style/invalidation/element/invalidator.rs
@@ -154,7 +154,7 @@ impl<'a, 'b: 'a, E> TreeStyleInvalidator
             trace!(" > visitedness change, force subtree restyle");
             // We can't just return here because there may also be attribute
             // changes as well that imply additional hints.
-            let mut data = self.data.as_mut().unwrap();
+            let data = self.data.as_mut().unwrap();
             data.restyle.hint.insert(RestyleHint::restyle_subtree());
         }
 
