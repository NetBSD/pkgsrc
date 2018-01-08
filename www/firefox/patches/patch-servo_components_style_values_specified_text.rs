$NetBSD: patch-servo_components_style_values_specified_text.rs,v 1.1 2018/01/08 09:37:57 ryoon Exp $

--- servo/components/style/values/specified/text.rs.orig	2017-11-02 16:16:34.000000000 +0000
+++ servo/components/style/values/specified/text.rs
@@ -7,7 +7,6 @@
 use cssparser::Parser;
 use parser::{Parse, ParserContext};
 use selectors::parser::SelectorParseError;
-use std::ascii::AsciiExt;
 use style_traits::ParseError;
 use values::computed::{Context, ToComputedValue};
 use values::computed::text::LineHeight as ComputedLineHeight;
