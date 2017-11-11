$NetBSD: patch-vendor_mozrunner_src_runner.rs,v 1.1 2017/11/11 20:25:56 tnn Exp $

Make the fallback method for finding the default browser behave like Linux.

--- ../vendor/mozrunner-0.5.0/src/runner.rs.orig	2017-09-11 14:07:59.000000000 +0000
+++ ../vendor/mozrunner-0.5.0/src/runner.rs
@@ -318,10 +318,11 @@ pub mod platform {
 
 #[cfg(not(any(target_os = "linux", target_os = "macos", target_os = "windows")))]
 pub mod platform {
+    use super::find_binary;
     use std::path::PathBuf;
 
     pub fn firefox_default_path() -> Option<PathBuf> {
-        None
+        find_binary("firefox")
     }
 
     pub fn arg_prefix_char(c: char) -> bool {
