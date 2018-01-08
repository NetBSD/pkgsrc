$NetBSD: patch-servo_components_style_properties_longhand_pointing.mako.rs,v 1.1 2018/01/08 09:37:57 ryoon Exp $

--- servo/components/style/properties/longhand/pointing.mako.rs.orig	2017-11-02 16:16:34.000000000 +0000
+++ servo/components/style/properties/longhand/pointing.mako.rs
@@ -90,7 +90,6 @@
     impl Parse for computed_value::Keyword {
         fn parse<'i, 't>(_context: &ParserContext, input: &mut Parser<'i, 't>)
                          -> Result<computed_value::Keyword, ParseError<'i>> {
-            use std::ascii::AsciiExt;
             use style_traits::cursor::Cursor;
             let ident = input.expect_ident()?;
             if ident.eq_ignore_ascii_case("auto") {
