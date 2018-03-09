$NetBSD: patch-servo_components_style_values_mod.rs,v 1.2.2.2 2018/03/09 07:17:30 spz Exp $

--- servo/components/style/values/mod.rs.orig	2017-11-02 16:16:34.000000000 +0000
+++ servo/components/style/values/mod.rs
@@ -12,7 +12,6 @@ use Atom;
 pub use cssparser::{RGBA, Token, Parser, serialize_identifier, BasicParseError, CowRcStr};
 use parser::{Parse, ParserContext};
 use selectors::parser::SelectorParseError;
-use std::ascii::AsciiExt;
 use std::fmt::{self, Debug};
 use std::hash;
 use style_traits::{ToCss, ParseError, StyleParseError};
