$NetBSD: patch-servo_components_script_dom_range.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/script/dom/range.rs.orig	2017-09-14 20:15:56.000000000 +0000
+++ servo/components/script/dom/range.rs
@@ -1049,7 +1049,7 @@ impl WeakRangeVec {
         let offset = context.index();
         let parent = context.parent;
         unsafe {
-            let mut ranges = &mut *self.cell.get();
+            let ranges = &mut *self.cell.get();
 
             ranges.update(|entry| {
                 let range = entry.root().unwrap();
@@ -1076,7 +1076,7 @@ impl WeakRangeVec {
         }
 
         unsafe {
-            let mut ranges = &mut *self.cell.get();
+            let ranges = &mut *self.cell.get();
 
             ranges.update(|entry| {
                 let range = entry.root().unwrap();
