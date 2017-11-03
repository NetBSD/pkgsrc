$NetBSD: patch-servo_components_layout_table__cell.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/layout/table_cell.rs.orig	2017-09-14 20:15:55.000000000 +0000
+++ servo/components/layout/table_cell.rs
@@ -136,7 +136,7 @@ impl TableCellFlow {
         }
 
         for kid in flow::mut_base(self).children.iter_mut() {
-            let mut kid_base = flow::mut_base(kid);
+            let kid_base = flow::mut_base(kid);
             if !kid_base.flags.contains(IS_ABSOLUTELY_POSITIONED) {
                 kid_base.position.start.b += offset
             }
