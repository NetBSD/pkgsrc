$NetBSD: patch-wezterm-font_src_lib.rs,v 1.1 2026/04/18 14:56:36 ktnb Exp $

Use fontconfig on Darwin as well

--- wezterm-font/src/lib.rs.orig	2026-01-17 15:44:28.000000000 +0000
+++ wezterm-font/src/lib.rs
@@ -32,7 +32,7 @@ pub mod rasterizer;
 pub mod shaper;
 pub mod units;
 
-#[cfg(all(unix, not(target_os = "macos")))]
+#[cfg(unix)]
 pub mod fcwrap;
 
 pub use crate::rasterizer::RasterizedGlyph;
