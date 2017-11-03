$NetBSD: patch-servo_components_script__plugins_unrooted__must__root.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/script_plugins/unrooted_must_root.rs.orig	2017-09-14 20:15:56.000000000 +0000
+++ servo/components/script_plugins/unrooted_must_root.rs
@@ -182,7 +182,7 @@ impl<'a, 'b, 'tcx> visit::Visitor<'tcx> 
         }
 
         match expr.node {
-            /// Trait casts from #[must_root] types are not allowed
+            // Trait casts from #[must_root] types are not allowed
             hir::ExprCast(ref subexpr, _) => require_rooted(cx, self.in_new_function, &*subexpr),
             // This catches assignments... the main point of this would be to catch mutable
             // references to `JS<T>`.
@@ -206,13 +206,21 @@ impl<'a, 'b, 'tcx> visit::Visitor<'tcx> 
     fn visit_pat(&mut self, pat: &'tcx hir::Pat) {
         let cx = self.cx;
 
-        if let hir::PatKind::Binding(hir::BindingMode::BindByValue(_), _, _, _) = pat.node {
-            let ty = cx.tables.pat_ty(pat);
-            if is_unrooted_ty(cx, ty, self.in_new_function) {
-                cx.span_lint(UNROOTED_MUST_ROOT,
-                            pat.span,
-                            &format!("Expression of type {:?} must be rooted", ty))
+        // We want to detect pattern bindings that move a value onto the stack.
+        // When "default binding modes" https://github.com/rust-lang/rust/issues/42640
+        // are implemented, the `Unannotated` case could cause false-positives.
+        // These should be fixable by adding an explicit `ref`.
+        match pat.node {
+            hir::PatKind::Binding(hir::BindingAnnotation::Unannotated, _, _, _) |
+            hir::PatKind::Binding(hir::BindingAnnotation::Mutable, _, _, _) => {
+                let ty = cx.tables.pat_ty(pat);
+                if is_unrooted_ty(cx, ty, self.in_new_function) {
+                    cx.span_lint(UNROOTED_MUST_ROOT,
+                                pat.span,
+                                &format!("Expression of type {:?} must be rooted", ty))
+                }
             }
+            _ => {}
         }
 
         visit::walk_pat(self, pat);
