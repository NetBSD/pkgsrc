$NetBSD: patch-servo_components_style_values_specified_mod.rs,v 1.1 2018/01/08 09:37:57 ryoon Exp $

--- servo/components/style/values/specified/mod.rs.orig	2017-11-02 16:16:34.000000000 +0000
+++ servo/components/style/values/specified/mod.rs
@@ -11,7 +11,6 @@ use context::QuirksMode;
 use cssparser::{Parser, Token, serialize_identifier, BasicParseError};
 use parser::{ParserContext, Parse};
 use self::url::SpecifiedUrl;
-use std::ascii::AsciiExt;
 use std::f32;
 use std::fmt;
 use style_traits::{ToCss, ParseError, StyleParseError};
