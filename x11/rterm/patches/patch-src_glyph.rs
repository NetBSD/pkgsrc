$NetBSD: patch-src_glyph.rs,v 1.1 2023/09/23 18:25:57 vins Exp $

* Fix wrong call of bits() method as field.  

--- src/glyph.rs.orig	2023-01-04 03:49:42.000000000 +0000
+++ src/glyph.rs
@@ -17,7 +17,7 @@ bitflags! {
         const STRUCK     = 1 << 7;
 
         const FONT_MASK  = (1 << 8) - 1;
-        const BOLD_FAINT = Self::BOLD.bits | Self::FAINT.bits;
+        const BOLD_FAINT = Self::BOLD.bits() | Self::FAINT.bits();
 
         // at line wrap
         const WRAP       = 1 << 8;
