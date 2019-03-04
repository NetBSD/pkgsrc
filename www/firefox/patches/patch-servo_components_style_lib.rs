$NetBSD: patch-servo_components_style_lib.rs,v 1.1 2019/03/04 15:53:06 ryoon Exp $

* Fix build with lang/rust-1.33.0

--- servo/components/style/lib.rs.orig	2019-02-27 22:18:28.000000000 +0000
+++ servo/components/style/lib.rs
@@ -23,8 +23,6 @@
 //! [cssparser]: ../cssparser/index.html
 //! [selectors]: ../selectors/index.html
 
-#![deny(missing_docs)]
-
 extern crate app_units;
 extern crate arrayvec;
 extern crate atomic_refcell;
