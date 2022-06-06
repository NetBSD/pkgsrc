$NetBSD: patch-src_bltScrollbar.c,v 1.1 2022/06/06 04:27:14 dholland Exp $

Update for tcl 8.6 (?) and don't use sprintf.

--- src/bltScrollbar.c~	2002-07-17 22:38:54.000000000 +0000
+++ src/bltScrollbar.c
@@ -534,7 +534,8 @@ ScrollbarWidgetCmd(clientData, interp, a
 	} else {
 	    fraction = ((double)pixels / (double)barWidth);
 	}
-	sprintf(interp->result, "%g", fraction);
+	snprintf(string, sizeof(string), "%g", fraction);
+	Tcl_SetResult(interp, string, TCL_VOLATILE);
     } else if ((c == 'f') && (strncmp(argv[1], "fraction", length) == 0)) {
 	int x, y, pos, barWidth;
 	double fraction;
@@ -567,7 +568,7 @@ ScrollbarWidgetCmd(clientData, interp, a
 	} else if (fraction > 1.0) {
 	    fraction = 1.0;
 	}
-	sprintf(string, "%g", fraction);
+	snprintf(string, sizeof(string), "%g", fraction);
 	Tcl_SetResult(interp, string, TCL_VOLATILE);
     } else if ((c == 'g') && (strncmp(argv[1], "get", length) == 0)) {
 	if (argc != 2) {
@@ -582,7 +583,8 @@ ScrollbarWidgetCmd(clientData, interp, a
 	    Tcl_PrintDouble(interp, scrollPtr->lastFraction, last);
 	    Tcl_AppendResult(interp, first, " ", last, (char *)NULL);
 	} else {
-	    sprintf(string, "%d %d %d %d", scrollPtr->totalUnits,
+	    snprintf(string, sizeof(string),
+	        "%d %d %d %d", scrollPtr->totalUnits,
 		scrollPtr->windowUnits, scrollPtr->firstUnit,
 		scrollPtr->lastUnit);
 	    Tcl_SetResult(interp, string, TCL_VOLATILE);
