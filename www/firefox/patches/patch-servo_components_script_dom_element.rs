$NetBSD: patch-servo_components_script_dom_element.rs,v 1.2.2.2 2018/03/09 07:17:30 spz Exp $

--- servo/components/script/dom/element.rs.orig	2017-11-02 16:16:33.000000000 +0000
+++ servo/components/script/dom/element.rs
@@ -95,7 +95,6 @@ use selectors::matching::{RelevantLinkSt
 use selectors::sink::Push;
 use servo_arc::Arc;
 use servo_atoms::Atom;
-use std::ascii::AsciiExt;
 use std::borrow::Cow;
 use std::cell::{Cell, Ref};
 use std::convert::TryFrom;
