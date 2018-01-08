$NetBSD: patch-servo_components_style_stylesheets_viewport__rule.rs,v 1.1 2018/01/08 09:37:57 ryoon Exp $

--- servo/components/style/stylesheets/viewport_rule.rs.orig	2017-11-02 16:16:34.000000000 +0000
+++ servo/components/style/stylesheets/viewport_rule.rs
@@ -20,7 +20,6 @@ use properties::StyleBuilder;
 use rule_cache::RuleCacheConditions;
 use selectors::parser::SelectorParseError;
 use shared_lock::{SharedRwLockReadGuard, StylesheetGuards, ToCssWithGuard};
-use std::ascii::AsciiExt;
 use std::borrow::Cow;
 use std::cell::RefCell;
 use std::fmt;
