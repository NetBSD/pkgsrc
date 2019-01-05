$NetBSD: patch-vendor_mozrunner_src_runner.rs,v 1.3 2019/01/05 03:01:30 tnn Exp $

Make the linux method the fallback method.

--- ../vendor/mozrunner-0.8.0/src/runner.rs.orig	2018-09-11 12:26:34.000000000 +0000
+++ ../vendor/mozrunner-0.8.0/src/runner.rs
@@ -293,21 +293,6 @@ impl Runner for FirefoxRunner {
     }
 }
 
-#[cfg(target_os = "linux")]
-pub mod platform {
-    use path::find_binary;
-    use std::path::PathBuf;
-
-    /// Searches the system path for `firefox`.
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
     use path::{find_binary, is_binary};
@@ -410,12 +395,12 @@ pub mod platform {
 
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
