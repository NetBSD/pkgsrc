$NetBSD: patch-libAfterStep_colorscheme.c,v 1.2 2021/07/11 12:13:17 bsiegert Exp $

Fix build with C99 inline.

--- libAfterStep/colorscheme.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterStep/colorscheme.c
@@ -129,7 +129,7 @@ int compare_color_lightness (ARGB32 c1, 
 			ASCS_BLACK_O_WHITE_CRITERIA16_VAL (red2, green2, blue2);
 }
 
-inline void
+static inline void
 make_grad_argb (ASColorScheme * cs, int id, ARGB32 base_alpha16,
 								int hue360, int sat100, int val100, Bool base)
 {
