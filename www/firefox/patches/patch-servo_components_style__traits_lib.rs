$NetBSD: patch-servo_components_style__traits_lib.rs,v 1.1 2019/03/04 15:53:06 ryoon Exp $

* Fix build with lang/rust-1.33.0

--- servo/components/style_traits/lib.rs.orig	2019-02-27 22:18:27.000000000 +0000
+++ servo/components/style_traits/lib.rs
@@ -8,7 +8,6 @@
 
 #![crate_name = "style_traits"]
 #![crate_type = "rlib"]
-#![deny(unsafe_code, missing_docs)]
 
 extern crate app_units;
 #[macro_use]
