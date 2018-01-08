$NetBSD: patch-servo_components_style_values_specified_align.rs,v 1.1 2018/01/08 09:37:57 ryoon Exp $

--- servo/components/style/values/specified/align.rs.orig	2017-11-02 16:16:34.000000000 +0000
+++ servo/components/style/values/specified/align.rs
@@ -10,7 +10,6 @@ use cssparser::Parser;
 use gecko_bindings::structs;
 use parser::{Parse, ParserContext};
 use selectors::parser::SelectorParseError;
-use std::ascii::AsciiExt;
 use std::fmt;
 use style_traits::{ToCss, ParseError, StyleParseError};
 
