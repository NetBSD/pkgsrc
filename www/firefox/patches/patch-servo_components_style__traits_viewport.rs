$NetBSD: patch-servo_components_style__traits_viewport.rs,v 1.2.2.2 2018/03/09 07:17:30 spz Exp $

--- servo/components/style_traits/viewport.rs.orig	2017-11-02 16:16:34.000000000 +0000
+++ servo/components/style_traits/viewport.rs
@@ -7,7 +7,6 @@
 use {CSSPixel, PinchZoomFactor, ParseError};
 use cssparser::{Parser, ToCss, ParseError as CssParseError, BasicParseError};
 use euclid::TypedSize2D;
-use std::ascii::AsciiExt;
 use std::fmt;
 
 define_css_keyword_enum!(UserZoom:
