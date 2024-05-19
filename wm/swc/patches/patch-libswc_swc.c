$NetBSD: patch-libswc_swc.c,v 1.4 2024/05/19 16:01:26 nia Exp $

Make starting xwayland non-fatal.

--- libswc/swc.c.orig	2024-05-19 15:53:22.716215256 +0000
+++ libswc/swc.c
@@ -199,7 +199,7 @@ swc_initialize(struct wl_display *displa
 #ifdef ENABLE_XWAYLAND
 	if (!xserver_initialize()) {
 		ERROR("Could not initialize xwayland\n");
-		goto error14;
+		/*goto error14;*/
 	}
 #endif
 
