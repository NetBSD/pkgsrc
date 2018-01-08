$NetBSD: patch-servo_components_style_values_mod.rs,v 1.1 2018/01/08 09:37:57 ryoon Exp $

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
