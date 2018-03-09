$NetBSD: patch-servo_components_style_values_specified_calc.rs,v 1.2.2.2 2018/03/09 07:17:30 spz Exp $

--- servo/components/style/values/specified/calc.rs.orig	2017-11-02 16:16:34.000000000 +0000
+++ servo/components/style/values/specified/calc.rs
@@ -8,7 +8,6 @@
 
 use cssparser::{Parser, Token, BasicParseError};
 use parser::ParserContext;
-use std::ascii::AsciiExt;
 use std::fmt;
 use style_traits::{ToCss, ParseError, StyleParseError};
 use style_traits::values::specified::AllowedNumericType;
