$NetBSD: patch-src_systray_systraybar.c,v 1.1 2015/02/08 18:06:10 tnn Exp $

Strict alignment. Upstream issue #273

--- src/systray/systraybar.c.orig	2010-06-09 15:31:18.000000000 +0000
+++ src/systray/systraybar.c
@@ -277,7 +277,7 @@ void start_net()
 
 	// v0.3 trayer specification. tint2 always horizontal.
 	// Vertical panel will draw the systray horizontal.
-	int orient = 0;
+	long orient = 0;
 	XChangeProperty(server.dsp, net_sel_win, server.atom._NET_SYSTEM_TRAY_ORIENTATION, XA_CARDINAL, 32, PropModeReplace, (unsigned char *) &orient, 1);
 	VisualID vid;
 	if (server.visual32 && (systray.alpha != 100 || systray.brightness != 0 || systray.saturation != 0))
