$NetBSD: patch-servo_components_script_dom_bindings_js.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/script/dom/bindings/js.rs.orig	2017-09-14 20:15:56.000000000 +0000
+++ servo/components/script/dom/bindings/js.rs
@@ -469,7 +469,7 @@ impl RootCollection {
     /// Start tracking a stack-based root
     unsafe fn root(&self, untracked_reflector: *const Reflector) {
         debug_assert!(thread_state::get().is_script());
-        let mut roots = &mut *self.roots.get();
+        let roots = &mut *self.roots.get();
         roots.push(untracked_reflector);
         assert!(!(*untracked_reflector).get_jsobject().is_null())
     }
@@ -479,7 +479,7 @@ impl RootCollection {
         assert!(!tracked_reflector.is_null());
         assert!(!(*tracked_reflector).get_jsobject().is_null());
         debug_assert!(thread_state::get().is_script());
-        let mut roots = &mut *self.roots.get();
+        let roots = &mut *self.roots.get();
         match roots.iter().rposition(|r| *r == tracked_reflector) {
             Some(idx) => {
                 roots.remove(idx);
