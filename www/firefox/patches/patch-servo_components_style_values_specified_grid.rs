$NetBSD: patch-servo_components_style_values_specified_grid.rs,v 1.1 2018/01/08 09:37:57 ryoon Exp $

--- servo/components/style/values/specified/grid.rs.orig	2017-11-02 16:16:34.000000000 +0000
+++ servo/components/style/values/specified/grid.rs
@@ -7,7 +7,6 @@
 
 use cssparser::{Parser, Token, BasicParseError};
 use parser::{Parse, ParserContext};
-use std::ascii::AsciiExt;
 use std::mem;
 use style_traits::{ParseError, StyleParseError};
 use values::{CSSFloat, CustomIdent};
