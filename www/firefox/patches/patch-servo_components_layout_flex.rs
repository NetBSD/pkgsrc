$NetBSD: patch-servo_components_layout_flex.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/layout/flex.rs.orig	2017-09-14 20:15:55.000000000 +0000
+++ servo/components/layout/flex.rs
@@ -415,7 +415,7 @@ impl FlexFlow {
 
         let items = &mut self.items[start..];
         let mut children = self.block_flow.base.children.random_access_mut();
-        for mut item in items {
+        for item in items {
             let kid = children.get(item.index);
             item.init_sizes(kid, container_size, self.main_mode);
             let outer_main_size = item.outer_main_size(kid, self.main_mode);
@@ -607,7 +607,7 @@ impl FlexFlow {
 
             let mut children = self.block_flow.base.children.random_access_mut();
             for item in items.iter_mut() {
-                let mut block = children.get(item.index).as_mut_block();
+                let block = children.get(item.index).as_mut_block();
 
                 block.base.block_container_writing_mode = container_mode;
                 block.base.block_container_inline_size = inline_size;
@@ -659,7 +659,7 @@ impl FlexFlow {
 
         let mut children = self.block_flow.base.children.random_access_mut();
         for item in &mut self.items {
-            let mut base = flow::mut_base(children.get(item.index));
+            let base = flow::mut_base(children.get(item.index));
             if !self.main_reverse {
                 base.position.start.b = cur_b;
                 cur_b = cur_b + base.position.size.block;
