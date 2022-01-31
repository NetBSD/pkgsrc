$NetBSD: patch-graphics__sixel.c,v 1.1 2022/01/31 10:00:24 wiz Exp $

Upstream patch to fix CVE-2022-24130.

--- graphics_sixel.c.orig	2021-08-10 00:39:26.000000000 +0000
+++ graphics_sixel.c
@@ -1,8 +1,8 @@
-/* $XTermId: graphics_sixel.c,v 1.29 2021/08/10 00:39:26 tom Exp $ */
+/* $XTermId: graphics_sixel.c,v 1.31 2022/01/31 08:53:42 tom Exp $ */
 
 /*
- * Copyright 2014-2020,2021 by Ross Combs
- * Copyright 2014-2020,2021 by Thomas E. Dickey
+ * Copyright 2014-2021,2022 by Ross Combs
+ * Copyright 2014-2021,2022 by Thomas E. Dickey
  *
  *                         All Rights Reserved
  *
@@ -149,7 +149,7 @@ init_sixel_background(Graphic *graphic, 
     graphic->color_registers_used[context->background] = 1;
 }
 
-static void
+static Boolean
 set_sixel(Graphic *graphic, SixelContext const *context, int sixel)
 {
     const int mh = graphic->max_height;
@@ -170,7 +170,10 @@ set_sixel(Graphic *graphic, SixelContext
 	   ((color != COLOR_HOLE)
 	    ? (unsigned) graphic->color_registers[color].b : 0U)));
     for (pix = 0; pix < 6; pix++) {
-	if (context->col < mw && context->row + pix < mh) {
+	if (context->col >= 0 &&
+	    context->col < mw &&
+	    context->row + pix >= 0 &&
+	    context->row + pix < mh) {
 	    if (sixel & (1 << pix)) {
 		if (context->col + 1 > graphic->actual_width) {
 		    graphic->actual_width = context->col + 1;
@@ -183,8 +186,10 @@ set_sixel(Graphic *graphic, SixelContext
 	    }
 	} else {
 	    TRACE(("sixel pixel %d out of bounds\n", pix));
+	    return False;
 	}
     }
+    return True;
 }
 
 static void
@@ -462,8 +467,12 @@ parse_sixel(XtermWidget xw, ANSI *params
 		init_sixel_background(graphic, &context);
 		graphic->valid = 1;
 	    }
-	    if (sixel)
-		set_sixel(graphic, &context, sixel);
+	    if (sixel) {
+		if (!set_sixel(graphic, &context, sixel)) {
+		    context.col = 0;
+		    break;
+		}
+	    }
 	    context.col++;
 	} else if (ch == '$') {	/* DECGCR */
 	    /* ignore DECCRNLM in sixel mode */
@@ -531,8 +540,12 @@ parse_sixel(XtermWidget xw, ANSI *params
 	    if (sixel) {
 		int i;
 		for (i = 0; i < Pcount; i++) {
-		    set_sixel(graphic, &context, sixel);
-		    context.col++;
+		    if (set_sixel(graphic, &context, sixel)) {
+			context.col++;
+		    } else {
+			context.col = 0;
+			break;
+		    }
 		}
 	    } else {
 		context.col += Pcount;
