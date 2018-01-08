$NetBSD: patch-servo_components_style_properties_longhand_font.mako.rs,v 1.1 2018/01/08 09:37:57 ryoon Exp $

--- servo/components/style/properties/longhand/font.mako.rs.orig	2017-11-28 04:17:05.000000000 +0000
+++ servo/components/style/properties/longhand/font.mako.rs
@@ -2144,7 +2144,6 @@ https://drafts.csswg.org/css-fonts-4/#lo
 
         #[inline]
         fn to_computed_value(&self, _context: &Context) -> computed_value::T {
-            use std::ascii::AsciiExt;
             match *self {
                 SpecifiedValue::Normal => computed_value::T(0),
                 SpecifiedValue::Override(ref lang) => {
