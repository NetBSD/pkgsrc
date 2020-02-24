$NetBSD: patch-libswc_swc.c,v 1.2 2020/02/24 14:23:53 nia Exp $

Disable decoration managers until this is stable.

Currently this causes problems quitting applications.

https://github.com/michaelforney/swc/issues/58

--- libswc/swc.c.orig	2020-02-22 10:04:33.000000000 +0000
+++ libswc/swc.c
@@ -169,7 +169,7 @@ swc_initialize(struct wl_display *displa
 		goto error10;
 	}
 
-	swc.xdg_decoration_manager = xdg_decoration_manager_create(display);
+	/*swc.xdg_decoration_manager = xdg_decoration_manager_create(display);
 	if (!swc.xdg_decoration_manager) {
 		ERROR("Could not initialize XDG decoration manager\n");
 		goto error11;
@@ -179,7 +179,7 @@ swc_initialize(struct wl_display *displa
 	if (!swc.kde_decoration_manager) {
 		ERROR("Could not initialize KDE decoration manager\n");
 		goto error12;
-	}
+	}*/
 
 	swc.panel_manager = panel_manager_create(display);
 	if (!swc.panel_manager) {
@@ -192,9 +192,9 @@ swc_initialize(struct wl_display *displa
 	return true;
 
 error13:
-	wl_global_destroy(swc.kde_decoration_manager);
+	/*wl_global_destroy(swc.kde_decoration_manager);*/
 error12:
-	wl_global_destroy(swc.xdg_decoration_manager);
+	/*wl_global_destroy(swc.xdg_decoration_manager);*/
 error11:
 	wl_global_destroy(swc.xdg_shell);
 error10:
@@ -225,7 +225,7 @@ EXPORT void
 swc_finalize(void)
 {
 	wl_global_destroy(swc.panel_manager);
-	wl_global_destroy(swc.xdg_decoration_manager);
+	/*wl_global_destroy(swc.xdg_decoration_manager);*/
 	wl_global_destroy(swc.xdg_shell);
 	wl_global_destroy(swc.shell);
 	seat_destroy(swc.seat);
