$NetBSD: patch-src_ewin-ops.c,v 1.1 2023/03/16 00:13:00 gutteridge Exp $

Keep window focus when un-fullscreened.
Upstream commit ee2da6a545cfdaadc1d1774fc46891f2b6695479
https://git.enlightenment.org/e16/e16/issues/5

--- src/ewin-ops.c.orig	2022-11-24 21:33:49.000000000 +0000
+++ src/ewin-ops.c
@@ -1307,6 +1307,10 @@ EwinOpFullscreen(EWin * ewin, int source
 	EwinStateUpdate(ewin);
 	EwinRaise(ewin);
 	EwinMoveResize(ewin, x, y, w, h, MRF_KEEP_MAXIMIZED);
+
+	/* Keep focus if focused */
+	if (ewin->state.active)
+	   FocusToEWin(ewin, FOCUS_SET);
      }
 
    HintsSetWindowState(ewin);
