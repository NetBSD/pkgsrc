$NetBSD: patch-servo_components_style_servo_selector__parser.rs,v 1.2.2.2 2018/03/09 07:17:30 spz Exp $

--- servo/components/style/servo/selector_parser.rs.orig	2017-11-02 16:16:34.000000000 +0000
+++ servo/components/style/servo/selector_parser.rs
@@ -21,7 +21,6 @@ use selectors::Element;
 use selectors::attr::{AttrSelectorOperation, NamespaceConstraint, CaseSensitivity};
 use selectors::parser::{SelectorMethods, SelectorParseError};
 use selectors::visitor::SelectorVisitor;
-use std::ascii::AsciiExt;
 use std::fmt;
 use std::fmt::Debug;
 use std::mem;
