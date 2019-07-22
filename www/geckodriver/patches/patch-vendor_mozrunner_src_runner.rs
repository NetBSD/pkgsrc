$NetBSD: patch-vendor_mozrunner_src_runner.rs,v 1.4 2019/07/22 23:48:31 tnn Exp $

Make the linux method the fallback method.

--- ../vendor/mozrunner-0.9.0/src/runner.rs.orig	2019-01-03 11:24:34.000000000 +0000
+++ ../vendor/mozrunner-0.9.0/src/runner.rs
@@ -410,12 +410,12 @@ pub mod platform {
 
 #[cfg(not(any(target_os = "linux", target_os = "macos", target_os = "windows")))]
 pub mod platform {
+    use path::find_binary;
     use std::path::PathBuf;
 
-    /// Returns `None` for all other operating systems than Linux, macOS, and
-    /// Windows.
+    /// Searches the system path for `firefox`.
     pub fn firefox_default_path() -> Option<PathBuf> {
-        None
+        find_binary("firefox")
     }
 
     pub fn arg_prefix_char(c: char) -> bool {
