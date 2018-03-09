$NetBSD: patch-servo_components_selectors_attr.rs,v 1.2.2.2 2018/03/09 07:17:30 spz Exp $

--- servo/components/selectors/attr.rs.orig	2017-11-02 16:16:33.000000000 +0000
+++ servo/components/selectors/attr.rs
@@ -4,7 +4,6 @@
 
 use cssparser::ToCss;
 use parser::SelectorImpl;
-use std::ascii::AsciiExt;
 use std::fmt;
 
 #[derive(Clone, Eq, PartialEq)]
