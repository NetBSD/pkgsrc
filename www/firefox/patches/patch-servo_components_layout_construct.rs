$NetBSD: patch-servo_components_layout_construct.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/layout/construct.rs.orig	2017-09-14 20:15:55.000000000 +0000
+++ servo/components/layout/construct.rs
@@ -1921,7 +1921,7 @@ impl Legalizer {
     /// true for anonymous block children of flex flows.
     fn try_to_add_child(&mut self, context: &SharedStyleContext, parent: &mut FlowRef, child: &mut FlowRef)
                         -> bool {
-        let mut parent = self.stack.last_mut().unwrap_or(parent);
+        let parent = self.stack.last_mut().unwrap_or(parent);
         let (parent_class, child_class) = (parent.class(), child.class());
         match (parent_class, child_class) {
             (FlowClass::TableWrapper, FlowClass::Table) |
@@ -1962,7 +1962,7 @@ impl Legalizer {
                     } else {
                         IS_BLOCK_FLEX_ITEM
                     };
-                    let mut block = FlowRef::deref_mut(&mut block_wrapper).as_mut_block();
+                    let block = FlowRef::deref_mut(&mut block_wrapper).as_mut_block();
                     block.base.flags.insert(MARGINS_CANNOT_COLLAPSE);
                     block.fragment.flags.insert(flag);
                 }
@@ -1979,7 +1979,7 @@ impl Legalizer {
                     } else {
                         IS_BLOCK_FLEX_ITEM
                     };
-                    let mut block = FlowRef::deref_mut(child).as_mut_block();
+                    let block = FlowRef::deref_mut(child).as_mut_block();
                     block.base.flags.insert(MARGINS_CANNOT_COLLAPSE);
                     block.fragment.flags.insert(flag);
                 }
