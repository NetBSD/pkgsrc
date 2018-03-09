$NetBSD: patch-servo_components_style_counter__style_mod.rs,v 1.2.2.2 2018/03/09 07:17:30 spz Exp $

--- servo/components/style/counter_style/mod.rs.orig	2017-11-02 16:16:33.000000000 +0000
+++ servo/components/style/counter_style/mod.rs
@@ -15,7 +15,6 @@ use error_reporting::{ContextualParseErr
 use parser::{ParserContext, ParserErrorContext, Parse};
 use selectors::parser::SelectorParseError;
 use shared_lock::{SharedRwLockReadGuard, ToCssWithGuard};
-use std::ascii::AsciiExt;
 use std::borrow::Cow;
 use std::fmt;
 use std::ops::Range;
