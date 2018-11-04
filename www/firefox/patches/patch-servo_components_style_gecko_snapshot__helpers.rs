$NetBSD: patch-servo_components_style_gecko_snapshot__helpers.rs,v 1.1 2018/11/04 00:38:45 ryoon Exp $

--- servo/components/style/gecko/snapshot_helpers.rs.orig	2018-10-18 20:06:10.000000000 +0000
+++ servo/components/style/gecko/snapshot_helpers.rs
@@ -60,7 +60,7 @@ pub fn find_attr<'a>(
     name: &Atom,
 ) -> Option<&'a structs::nsAttrValue> {
     attrs.iter()
-        .find(|attr| attr.mName.mBits == name.as_ptr() as usize)
+        .find(|attr| attr.mName.mBits == name.as_ptr() as @RUST_USIZE@)
         .map(|attr| &attr.mValue)
 }
 
