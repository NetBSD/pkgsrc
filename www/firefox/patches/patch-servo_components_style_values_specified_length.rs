$NetBSD: patch-servo_components_style_values_specified_length.rs,v 1.1 2018/01/08 09:37:57 ryoon Exp $

--- servo/components/style/values/specified/length.rs.orig	2017-11-02 16:16:34.000000000 +0000
+++ servo/components/style/values/specified/length.rs
@@ -12,7 +12,6 @@ use euclid::Size2D;
 use font_metrics::FontMetricsQueryResult;
 use parser::{Parse, ParserContext};
 use std::{cmp, fmt, mem};
-use std::ascii::AsciiExt;
 use std::ops::{Add, Mul};
 use style_traits::{ToCss, ParseError, StyleParseError};
 use style_traits::values::specified::AllowedNumericType;
