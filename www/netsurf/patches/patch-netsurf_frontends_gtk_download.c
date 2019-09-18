$NetBSD: patch-netsurf_frontends_gtk_download.c,v 1.1 2019/09/18 20:21:39 nros Exp $
* fix crash when downloading files (nullpointer dereference)
--- netsurf/frontends/gtk/download.c.orig	2019-07-17 15:37:00.000000000 +0000
+++ netsurf/frontends/gtk/download.c
@@ -89,6 +89,8 @@ struct gui_download_window {
 	GError *error;
 };
 
+bool nsgtk_download_FALSE = FALSE;
+
 typedef	void (*nsgtk_download_selection_action)(
 		struct gui_download_window *dl,
 		void *user_data);
@@ -838,7 +840,7 @@ gui_download_window_create(download_cont
 		g_timeout_add(
 			UPDATE_RATE,
 			nsgtk_download_gsourcefunc__nsgtk_download_update,
-			FALSE);
+			(gpointer) &nsgtk_download_FALSE);
 	}
 
 	nsgtk_downloads_list = g_list_prepend(nsgtk_downloads_list, download);
