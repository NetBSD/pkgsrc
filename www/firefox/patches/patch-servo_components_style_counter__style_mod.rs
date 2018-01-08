$NetBSD: patch-servo_components_style_counter__style_mod.rs,v 1.1 2018/01/08 09:37:57 ryoon Exp $

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
