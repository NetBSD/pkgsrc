$NetBSD: patch-wezterm-font_src_locator_mod.rs,v 1.1 2026/04/18 14:56:36 ktnb Exp $

Use fontconfig on Darwin as well.

--- wezterm-font/src/locator/mod.rs.orig	2026-01-17 15:44:28.000000000 +0000
+++ wezterm-font/src/locator/mod.rs
@@ -8,7 +8,7 @@ use std::path::PathBuf;
 use std::sync::Arc;
 
 pub mod core_text;
-#[cfg(all(unix, not(target_os = "macos")))]
+#[cfg(unix)]
 pub mod font_config;
 pub mod gdi;
 
@@ -222,9 +222,9 @@ pub trait FontLocator {
 pub fn new_locator(locator: FontLocatorSelection) -> Arc<dyn FontLocator + Send + Sync> {
     match locator {
         FontLocatorSelection::FontConfig => {
-            #[cfg(all(unix, not(target_os = "macos")))]
+            #[cfg(unix)]
             return Arc::new(font_config::FontConfigFontLocator {});
-            #[cfg(not(all(unix, not(target_os = "macos"))))]
+            #[cfg(not(unix))]
             panic!("fontconfig not compiled in");
         }
         FontLocatorSelection::CoreText => {
