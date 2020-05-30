$NetBSD: patch-gfx_cairo_cairo_src_cairo-type1-subset.c,v 1.1 2020/05/30 08:02:52 rillig Exp $

Fix undefined behavior when calling <ctype.h> functions with illegal values.

gfx/cairo/cairo/src/cairo-type1-subset.c:273:11: error: array subscript is of type 'char' [-Werror,-Wchar-subscripts]

https://bugzilla.mozilla.org/show_bug.cgi?id=1642081

--- gfx/cairo/cairo/src/cairo-type1-subset.c.orig	2020-05-07 18:34:10.000000000 +0000
+++ gfx/cairo/cairo/src/cairo-type1-subset.c
@@ -270,7 +270,7 @@ cairo_type1_font_subset_find_segments (c
 	font->eexec_segment = (char *) p + font->header_segment_size;
 	font->eexec_segment_is_ascii = TRUE;
 	for (i = 0; i < 4; i++) {
-	    if (!isxdigit(font->eexec_segment[i]))
+	    if (!isxdigit((unsigned char) font->eexec_segment[i]))
 		font->eexec_segment_is_ascii = FALSE;
 	}
     }
