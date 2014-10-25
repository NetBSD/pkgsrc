$NetBSD: patch-src_panel.c,v 1.1 2014/10/25 10:36:24 khorben Exp $

Fix for Gtk+ 2.24

--- src/panel.c.orig	2014-10-23 09:38:39.000000000 +0000
+++ src/panel.c
@@ -768,7 +768,7 @@ static GtkWidget * _preferences_window_p
 	for(i = 0; i < sizeof(titles) / sizeof(*titles); i++)
 	{
 #if GTK_CHECK_VERSION(2, 24, 0)
-		gtk_combo_box_append_text(GTK_COMBO_BOX(widget), _(titles[i]));
+		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(widget), _(titles[i]));
 #else
 		gtk_combo_box_append_text(GTK_COMBO_BOX(widget), _(titles[i]));
 #endif
@@ -782,11 +782,11 @@ static GtkWidget * _preferences_window_p
 				FALSE, TRUE, 0);
 		gtk_widget_set_no_show_all(panel->pr_panels[i].enabled, TRUE);
 		/* size */
-#if GTK_CHECK_VERSION(3, 0, 0)
+#if GTK_CHECK_VERSION(2, 24, 0)
 		panel->pr_panels[i].size = gtk_combo_box_text_new();
-		gtk_combo_box_text_append(
+		gtk_combo_box_text_append_text(
 				GTK_COMBO_BOX_TEXT(panel->pr_panels[i].size),
-				NULL, _("Default"));
+				_("Default"));
 #else
 		panel->pr_panels[i].size = gtk_combo_box_new_text();
 		gtk_combo_box_append_text(
@@ -796,9 +796,9 @@ static GtkWidget * _preferences_window_p
 		for(j = 0; j < sizeof(_panel_sizes) / sizeof(*_panel_sizes);
 				j++)
 		{
-#if GTK_CHECK_VERSION(3, 0, 0)
-			gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(
-						panel->pr_panels[i].size), NULL,
+#if GTK_CHECK_VERSION(2, 24, 0)
+			gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(
+						panel->pr_panels[i].size),
 					_(_panel_sizes[j].alias));
 #else
 			gtk_combo_box_append_text(
