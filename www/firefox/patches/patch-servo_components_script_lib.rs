$NetBSD: patch-servo_components_script_lib.rs,v 1.1 2017/11/03 22:07:27 ryoon Exp $

--- servo/components/script/lib.rs.orig	2017-09-14 20:15:56.000000000 +0000
+++ servo/components/script/lib.rs
@@ -9,7 +9,6 @@
 #![feature(mpsc_select)]
 #![feature(nonzero)]
 #![feature(on_unimplemented)]
-#![feature(option_entry)]
 #![feature(plugin)]
 #![feature(proc_macro)]
 #![feature(stmt_expr_attributes)]
