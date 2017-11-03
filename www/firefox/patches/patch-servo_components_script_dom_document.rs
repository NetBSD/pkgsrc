$NetBSD: patch-servo_components_script_dom_document.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/script/dom/document.rs.orig	2017-09-14 20:15:56.000000000 +0000
+++ servo/components/script/dom/document.rs
@@ -633,7 +633,7 @@ impl Document {
         // reset_form_owner_for_listeners -> reset_form_owner -> GetElementById
         {
             let mut id_map = self.id_map.borrow_mut();
-            let mut elements = id_map.entry(id.clone()).or_insert(Vec::new());
+            let elements = id_map.entry(id.clone()).or_insert(Vec::new());
             elements.insert_pre_order(element, root.r().upcast::<Node>());
         }
         self.reset_form_owner_for_listeners(&id);
@@ -642,7 +642,7 @@ impl Document {
     pub fn register_form_id_listener<T: ?Sized + FormControl>(&self, id: DOMString, listener: &T) {
         let mut map = self.form_id_listener_map.borrow_mut();
         let listener = listener.to_element();
-        let mut set = map.entry(Atom::from(id)).or_insert(HashSet::new());
+        let set = map.entry(Atom::from(id)).or_insert(HashSet::new());
         set.insert(JS::from_ref(listener));
     }
 
@@ -1572,7 +1572,7 @@ impl Document {
     /// https://html.spec.whatwg.org/multipage/#dom-window-cancelanimationframe
     pub fn cancel_animation_frame(&self, ident: u32) {
         let mut list = self.animation_frame_list.borrow_mut();
-        if let Some(mut pair) = list.iter_mut().find(|pair| pair.0 == ident) {
+        if let Some(pair) = list.iter_mut().find(|pair| pair.0 == ident) {
             pair.1 = None;
         }
     }
@@ -2399,7 +2399,7 @@ impl Document {
         if entry.snapshot.is_none() {
             entry.snapshot = Some(Snapshot::new(el.html_element_in_html_document()));
         }
-        let mut snapshot = entry.snapshot.as_mut().unwrap();
+        let snapshot = entry.snapshot.as_mut().unwrap();
         if snapshot.state.is_none() {
             snapshot.state = Some(el.state());
         }
@@ -2426,7 +2426,7 @@ impl Document {
             entry.hint.insert(RESTYLE_SELF);
         }
 
-        let mut snapshot = entry.snapshot.as_mut().unwrap();
+        let snapshot = entry.snapshot.as_mut().unwrap();
         if attr.local_name() == &local_name!("id") {
             snapshot.id_changed = true;
         } else if attr.local_name() == &local_name!("class") {
@@ -4028,7 +4028,7 @@ impl PendingInOrderScriptVec {
 
     fn loaded(&self, element: &HTMLScriptElement, result: ScriptResult) {
         let mut scripts = self.scripts.borrow_mut();
-        let mut entry = scripts.iter_mut().find(|entry| &*entry.element == element).unwrap();
+        let entry = scripts.iter_mut().find(|entry| &*entry.element == element).unwrap();
         entry.loaded(result);
     }
 
