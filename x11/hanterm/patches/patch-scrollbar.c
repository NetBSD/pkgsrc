$NetBSD: patch-scrollbar.c,v 1.1 2013/11/24 05:53:52 dholland Exp $

- use standard headers
- silence warnings about int/pointer casts
- don't declare own realloc/calloc

--- scrollbar.c~	1999-03-19 06:27:19.000000000 +0000
+++ scrollbar.c
@@ -28,6 +28,8 @@
 #include "ptyx.h"		/* gets Xt headers, too */
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <stdint.h>
 #include <ctype.h>
 #include <X11/Xatom.h>
 
@@ -313,9 +315,6 @@ void ScrollBarOn (xw, init, doalloc)
 	register TScreen *screen = &xw->screen;
 	register int border = 2 * screen->border;
 	register int i;
-#if	!defined(linux) || (__GNUC__<2)
-	Char *realloc(), *calloc();
-#endif
 
 	if(screen->scrollbar)
 		return;
@@ -423,7 +422,7 @@ static void ScrollTextUpDownBy(scrollbar
 	XtPointer client_data;
 	XtPointer call_data;
 {
-	int pixels = (int) call_data;
+	int pixels = (intptr_t) call_data;
 
 	register TScreen *screen = &term->screen;
 	register int rowOnScreen, newTopLine;
@@ -508,9 +507,11 @@ void HandleScrollForward (gw, event, par
 {
     XtermWidget w = (XtermWidget) gw;
     register TScreen *screen = &w->screen;
+    int pixels;
 
+    pixels = params_to_pixels (screen, params, (int) *nparams);
     ScrollTextUpDownBy (gw, (XtPointer) NULL,
-			(XtPointer)params_to_pixels (screen, params, (int) *nparams));
+			(XtPointer)(intptr_t)pixels);
     return;
 }
 
@@ -523,8 +524,10 @@ void HandleScrollBack (gw, event, params
 {
     XtermWidget w = (XtermWidget) gw;
     register TScreen *screen = &w->screen;
+    int pixels;
 
+    pixels = -params_to_pixels (screen, params, (int) *nparams);
     ScrollTextUpDownBy (gw, (XtPointer) NULL,
-			(XtPointer)-params_to_pixels (screen, params, (int) *nparams));
+			(XtPointer)(intptr_t)pixels);
     return;
 }
