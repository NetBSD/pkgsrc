$NetBSD: patch-servo_components_style_str.rs,v 1.1 2018/01/08 09:37:57 ryoon Exp $

--- servo/components/style/str.rs.orig	2017-11-02 16:16:34.000000000 +0000
+++ servo/components/style/str.rs
@@ -7,7 +7,6 @@
 #![deny(missing_docs)]
 
 use num_traits::ToPrimitive;
-use std::ascii::AsciiExt;
 use std::borrow::Cow;
 use std::convert::AsRef;
 use std::iter::{Filter, Peekable};
