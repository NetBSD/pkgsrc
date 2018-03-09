$NetBSD: patch-servo_components_style_values_specified_length.rs,v 1.2.2.2 2018/03/09 07:17:30 spz Exp $

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
