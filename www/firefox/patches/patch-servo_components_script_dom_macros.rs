$NetBSD: patch-servo_components_script_dom_macros.rs,v 1.2.2.2 2018/03/09 07:17:30 spz Exp $

--- servo/components/script/dom/macros.rs.orig	2017-11-02 16:16:33.000000000 +0000
+++ servo/components/script/dom/macros.rs
@@ -149,7 +149,6 @@ macro_rules! make_enumerated_getter(
         fn $attr(&self) -> DOMString {
             use dom::bindings::inheritance::Castable;
             use dom::element::Element;
-            use std::ascii::AsciiExt;
             let element = self.upcast::<Element>();
             let mut val = element.get_string_attribute(&local_name!($htmlname));
             val.make_ascii_lowercase();
