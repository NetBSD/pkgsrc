$NetBSD: patch-servo_components_script_dom_cssstyledeclaration.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/script/dom/cssstyledeclaration.rs.orig	2017-09-14 20:15:56.000000000 +0000
+++ servo/components/script/dom/cssstyledeclaration.rs
@@ -238,7 +238,7 @@ impl CSSStyleDeclaration {
             return Err(Error::NoModificationAllowed);
         }
 
-        self.owner.mutate_associated_block(|ref mut pdb, mut changed| {
+        self.owner.mutate_associated_block(|pdb, changed| {
             if value.is_empty() {
                 // Step 3
                 *changed = pdb.remove_property(&id);
@@ -360,7 +360,7 @@ impl CSSStyleDeclarationMethods for CSSS
             _ => return Ok(()),
         };
 
-        self.owner.mutate_associated_block(|ref mut pdb, mut changed| {
+        self.owner.mutate_associated_block(|pdb, changed| {
             // Step 5 & 6
             *changed = pdb.set_importance(&id, importance);
         });
@@ -388,7 +388,7 @@ impl CSSStyleDeclarationMethods for CSSS
         };
 
         let mut string = String::new();
-        self.owner.mutate_associated_block(|mut pdb, mut changed| {
+        self.owner.mutate_associated_block(|pdb, changed| {
             pdb.property_value_to_css(&id, &mut string).unwrap();
             *changed = pdb.remove_property(&id);
         });
@@ -438,7 +438,7 @@ impl CSSStyleDeclarationMethods for CSSS
         }
 
         let quirks_mode = window.Document().quirks_mode();
-        self.owner.mutate_associated_block(|mut pdb, mut _changed| {
+        self.owner.mutate_associated_block(|pdb, _changed| {
             // Step 3
             *pdb = parse_style_attribute(&value,
                                          &self.owner.base_url(),
