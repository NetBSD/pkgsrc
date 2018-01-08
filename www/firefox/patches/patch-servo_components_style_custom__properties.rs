$NetBSD: patch-servo_components_style_custom__properties.rs,v 1.1 2018/01/08 09:37:57 ryoon Exp $

--- servo/components/style/custom_properties.rs.orig	2017-11-02 16:16:33.000000000 +0000
+++ servo/components/style/custom_properties.rs
@@ -14,7 +14,6 @@ use properties::{CSSWideKeyword, Declare
 use selector_map::{PrecomputedHashSet, PrecomputedHashMap};
 use selectors::parser::SelectorParseError;
 use servo_arc::Arc;
-use std::ascii::AsciiExt;
 use std::borrow::{Borrow, Cow};
 use std::fmt;
 use std::hash::Hash;
