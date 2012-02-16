$NetBSD: patch-src_gtk_settings.cpp,v 1.1 2012/02/16 20:26:18 hans Exp $

--- src/gtk/settings.cpp	2012-01-15 17:42:01.818106898 +0100
+++ src/gtk/settings.cpp.orig	2003-09-21 13:31:57.000000000 +0200
@@ -340,8 +340,8 @@ wxFont wxSystemSettingsNative::GetFont( 
                 }  
                 else  
                 {  
-                    const gchar *font_name =
-                        _gtk_rc_context_get_default_font_name(gtk_settings_get_default());
+                    gchar *font_name;
+                    g_object_get(gtk_settings_get_default(), "gtk-font-name", &font_name, NULL);
                     g_systemFont = new wxFont(wxString::FromAscii(font_name));
                 }  
                 gtk_widget_destroy( widget );
