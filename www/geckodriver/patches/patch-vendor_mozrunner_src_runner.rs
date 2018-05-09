$NetBSD: patch-vendor_mozrunner_src_runner.rs,v 1.2 2018/05/09 23:41:39 maya Exp $

Make the linux method the fallback method.

--- ../vendor/mozrunner-0.6.1/src/runner.rs.orig	2017-09-11 14:07:59.000000000 +0000
+++ ../vendor/mozrunner-0.6.1/src/runner.rs
@@ -351,20 +351,6 @@ fn find_binary(name: &str) -> Option<Pat
     })
 }
 
-#[cfg(target_os = "linux")]
-pub mod platform {
-    use super::find_binary;
-    use std::path::PathBuf;
-
-    pub fn firefox_default_path() -> Option<PathBuf> {
-        find_binary("firefox")
-    }
-
-    pub fn arg_prefix_char(c: char) -> bool {
-        c == '-'
-    }
-}
-
 #[cfg(target_os = "macos")]
 pub mod platform {
     use super::find_binary;
@@ -455,12 +441,13 @@ pub mod platform {
     }
 }
 
-#[cfg(not(any(target_os = "linux", target_os = "macos", target_os = "windows")))]
+#[cfg(not(any(target_os = "macos", target_os = "windows")))]
 pub mod platform {
+    use super::find_binary;
     use std::path::PathBuf;
 
     pub fn firefox_default_path() -> Option<PathBuf> {
-        None
+        find_binary("firefox")
     }
 
     pub fn arg_prefix_char(c: char) -> bool {
