$NetBSD: patch-x.c,v 1.1 2020/11/15 20:36:37 nat Exp $
Fix display for color depths lower than 4bpp.
--- x.c.orig	2019-08-28 13:01:46.000000000 +0000
+++ x.c
@@ -1663,12 +1663,12 @@ static unsigned char *x_init_driver(unsi
 
 	/* find best visual */
 	{
-		static_const unsigned char depths[] = {24, 16, 15, 8, 4};
-		static_const int classes[] = {TrueColor, PseudoColor, StaticColor}; /* FIXME: dodelat DirectColor */
+		static_const unsigned char depths[] = {24, 16, 15, 8, 4, 2, 1};
+		static_const int classes[] = {TrueColor, PseudoColor, StaticColor, StaticGray}; /* FIXME: dodelat DirectColor */
 		unsigned a, b;
 
 		for (a = 0; a < array_elements(depths); a++) for (b = 0; b < array_elements(classes); b++) {
-			if ((classes[b] == PseudoColor || classes[b] == StaticColor) && depths[a] > 8)
+			if ((classes[b] == PseudoColor || classes[b] == StaticColor || classes[b] == StaticGray) && depths[a] > 8)
 				continue;
 			if (classes[b] == TrueColor && depths[a] <= 8)
 				continue;
@@ -1696,11 +1696,13 @@ bytes_per_pixel_found:
 				/* test misordered flag */
 				/*debug("x_depth %d, x_bitmap_bpp %d %lx %lx %lx %s", x_depth, x_bitmap_bpp, vinfo.red_mask, vinfo.green_mask, vinfo.blue_mask, x_bitmap_bit_order == MSBFirst ? "MSBFirst" : "LSBFirst");*/
 				switch (x_depth) {
+					case 1:
+					case 2:
 					case 4:
 					case 8:
 						if (x_bitmap_bpp != 1)
 							break;
-						if (vinfo.class == StaticColor || vinfo.class == PseudoColor) {
+						if (vinfo.class == StaticColor || vinfo.class == PseudoColor || vinfo.class == StaticGray) {
 							misordered = 0;
 							goto visual_found;
 						}
@@ -1755,7 +1757,7 @@ visual_found:
 	x_driver.flags &= ~GD_SWITCH_PALETTE;
 	x_have_palette = 0;
 	x_use_static_color_table = 0;
-	if (vinfo.class == StaticColor) {
+	if (vinfo.class == StaticColor || vinfo.class == StaticGray) {
 		if (x_depth > 8)
 			return stracpy(cast_uchar "Static color supported for up to 8-bit depth.\n");
 		if ((err = x_query_palette()))
@@ -2219,13 +2221,32 @@ static void x_translate_colors(unsigned 
 		return;
 	}
 
+	unsigned char *mypic = data;
 	if (x_use_static_color_table) {
 		for (j = 0; j < y; j++) {
 			for (i = 0; i < x; i++)
 				data[i] = static_color_table[data[i]];
 			data += skip;
 		}
-		return;
+	}
+	if (x_depth == 1) {
+		unsigned char s;
+		for (j = 0; j < y; j++) {
+			s = 0;
+			for (i = 0; i < x; i++) {
+				if (mypic[i])
+					s |= 1;
+				if (i % 8 == 7) {
+					mypic[i / 8] = s;
+					s = 0;
+				} else if (i == (x - 1)) {
+					s <<= (8 - ((i + 1) % 8));
+					mypic[i / 8] = s;
+				} else
+					s <<= 1;
+			}
+			mypic += skip;
+		}
 	}
 }
 
