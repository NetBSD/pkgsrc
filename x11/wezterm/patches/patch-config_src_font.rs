$NetBSD: patch-config_src_font.rs,v 1.1 2026/04/18 14:56:36 ktnb Exp $

Use fontconfig unless distro-defaults is disabled on Darwin

--- config/src/font.rs.orig	2026-01-17 15:44:28.000000000 +0000
+++ config/src/font.rs
@@ -678,7 +678,7 @@ impl Default for FontLocatorSelection {
     fn default() -> Self {
         if cfg!(windows) {
             FontLocatorSelection::Gdi
-        } else if cfg!(target_os = "macos") {
+        } else if cfg!(all(target_os = "macos", not(feature = "distro-defaults"))) {
             FontLocatorSelection::CoreText
         } else {
             FontLocatorSelection::FontConfig
