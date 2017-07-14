$NetBSD: patch-libAfterStep_colorscheme.c,v 1.1 2017/07/14 12:52:49 joerg Exp $

Fix build with C99 inline.

--- libAfterStep/colorscheme.c.orig	2017-07-12 21:35:22.546616813 +0000
+++ libAfterStep/colorscheme.c
@@ -122,7 +122,7 @@ compare_color_lightness( ARGB32 c1, ARGB
 	return ASCS_BLACK_O_WHITE_CRITERIA16_VAL( red1, green1, blue1 )-ASCS_BLACK_O_WHITE_CRITERIA16_VAL( red2, green2, blue2 );
 }
 
-inline void
+static inline void
 make_grad_argb( ASColorScheme *cs, int id,  ARGB32 base_alpha16, int hue360, int sat100, int val100, Bool base )
 {
 	int dark_val = val100-ASCS_GRADIENT_BRIGHTNESS_OFFSET ;
