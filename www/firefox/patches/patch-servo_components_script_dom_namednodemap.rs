$NetBSD: patch-servo_components_script_dom_namednodemap.rs,v 1.1 2018/01/08 09:37:57 ryoon Exp $

--- servo/components/script/dom/namednodemap.rs.orig	2017-07-31 16:20:53.000000000 +0000
+++ servo/components/script/dom/namednodemap.rs
@@ -15,7 +15,6 @@ use dom::element::Element;
 use dom::window::Window;
 use dom_struct::dom_struct;
 use html5ever::LocalName;
-use std::ascii::AsciiExt;
 
 #[dom_struct]
 pub struct NamedNodeMap {
