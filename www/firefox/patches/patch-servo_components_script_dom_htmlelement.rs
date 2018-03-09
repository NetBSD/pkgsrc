$NetBSD: patch-servo_components_script_dom_htmlelement.rs,v 1.2.2.2 2018/03/09 07:17:30 spz Exp $

--- servo/components/script/dom/htmlelement.rs.orig	2017-11-02 16:16:33.000000000 +0000
+++ servo/components/script/dom/htmlelement.rs
@@ -30,7 +30,6 @@ use dom::nodelist::NodeList;
 use dom::virtualmethods::VirtualMethods;
 use dom_struct::dom_struct;
 use html5ever::{LocalName, Prefix};
-use std::ascii::AsciiExt;
 use std::default::Default;
 use std::rc::Rc;
 use style::attr::AttrValue;
