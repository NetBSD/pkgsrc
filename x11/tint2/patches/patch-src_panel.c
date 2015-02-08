$NetBSD: patch-src_panel.c,v 1.1 2015/02/08 18:06:10 tnn Exp $

Strict alignment. Upstream issue #273

--- src/panel.c.orig	2010-06-26 12:35:35.000000000 +0000
+++ src/panel.c
@@ -493,7 +493,7 @@ void set_panel_properties(Panel *p)
 	XChangeProperty(server.dsp, p->main_win, server.atom._MOTIF_WM_HINTS, server.atom._MOTIF_WM_HINTS, 32, PropModeReplace, (unsigned char *) prop, 5);
 
 	// XdndAware - Register for Xdnd events
-	int version=5;
+	long version=5;
 	XChangeProperty(server.dsp, p->main_win, server.atom.XdndAware, XA_ATOM, 32, PropModeReplace, (unsigned char*)&version, 1);
 
 	update_strut(p);
