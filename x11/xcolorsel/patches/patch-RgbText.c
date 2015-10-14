$NetBSD: patch-RgbText.c,v 1.2 2015/10/14 20:17:28 wiz Exp $

--- RgbText.c.orig	1994-12-13 22:13:27.000000000 +0000
+++ RgbText.c
@@ -78,7 +78,6 @@
 #include <stdlib.h>
 /* And here we have a special gift for all SUN's outside >;-> */
 #include <unistd.h>
-#include <malloc.h>
 #include <ctype.h>
 #include <errno.h>
 #include <X11/IntrinsicP.h>
@@ -146,7 +145,7 @@ static XtResource resources[] = {
 { XtNcolumns, XtCColumns, XtRDimension, sizeof(Dimension), offset(columns),
 		XtRString, (XtPointer) "30" },
 { XtNfile, XtCFile, XtRString, sizeof(String), offset(file),
-		XtRString, (XtPointer) "/usr/lib/X11/rgb.txt" },
+		XtRString, (XtPointer) "/usr/pkg/X11/rgb.txt" },
 { XtNtileWidth, XtCTileWidth, XtRDimension, sizeof(Dimension), offset(tile_width),
 		XtRString, (XtPointer) "3" },
 { XtNmaxRed, XtCMaxRed, XtRShort, sizeof(unsigned short), offset(max_red),
