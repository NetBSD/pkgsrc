$NetBSD: patch-servo_components_style_values_specified_percentage.rs,v 1.1 2018/01/08 09:37:57 ryoon Exp $

--- servo/components/style/values/specified/percentage.rs.orig	2017-11-02 16:16:34.000000000 +0000
+++ servo/components/style/values/specified/percentage.rs
@@ -6,7 +6,6 @@
 
 use cssparser::{BasicParseError, Parser, Token};
 use parser::{Parse, ParserContext};
-use std::ascii::AsciiExt;
 use std::fmt;
 use style_traits::{ParseError, ToCss};
 use style_traits::values::specified::AllowedNumericType;
