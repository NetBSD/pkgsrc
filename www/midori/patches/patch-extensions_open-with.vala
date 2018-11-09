$NetBSD: patch-extensions_open-with.vala,v 1.1 2018/11/09 09:17:07 abs Exp $

Update to build against vala-0.42.0

--- extensions/open-with.vala.orig	2015-08-30 11:56:26.000000000 +0000
+++ extensions/open-with.vala
@@ -161,10 +161,10 @@ namespace ExternalApplications {
             has_separator = false;
 #endif
             destroy_with_parent = true;
-            set_icon_name (Gtk.STOCK_OPEN);
+            set_icon_name (Gtk.Stock.OPEN);
             resizable = false;
-            add_buttons (Gtk.STOCK_CANCEL, Gtk.ResponseType.CANCEL,
-                         Gtk.STOCK_SAVE, Gtk.ResponseType.ACCEPT);
+            add_buttons (Gtk.Stock.CANCEL, Gtk.ResponseType.CANCEL,
+                         Gtk.Stock.SAVE, Gtk.ResponseType.ACCEPT);
 
             var vbox = new Gtk.VBox (false, 8);
             vbox.border_width = 8;
@@ -266,7 +266,7 @@ namespace ExternalApplications {
 
                 var menu = new Gtk.Menu ();
                 var menuitem = new Gtk.ImageMenuItem.with_mnemonic (_("Custom…"));
-                menuitem.image = new Gtk.Image.from_stock (Gtk.STOCK_EDIT, Gtk.IconSize.MENU);
+                menuitem.image = new Gtk.Image.from_stock (Gtk.Stock.EDIT, Gtk.IconSize.MENU);
                 menuitem.activate.connect (() => {
                     customize_app_info (app_info, content_type, uri);
                 });
@@ -374,10 +374,10 @@ namespace ExternalApplications {
             has_separator = false;
 #endif
             destroy_with_parent = true;
-            set_icon_name (Gtk.STOCK_OPEN);
+            set_icon_name (Gtk.Stock.OPEN);
             resizable = true;
-            add_buttons (Gtk.STOCK_CANCEL, Gtk.ResponseType.CANCEL,
-                         Gtk.STOCK_OPEN, Gtk.ResponseType.ACCEPT);
+            add_buttons (Gtk.Stock.CANCEL, Gtk.ResponseType.CANCEL,
+                         Gtk.Stock.OPEN, Gtk.ResponseType.ACCEPT);
 
             var vbox = new Gtk.VBox (false, 8);
             vbox.border_width = 8;
@@ -740,7 +740,7 @@ namespace ExternalApplications {
 
         void show_preferences (Katze.Preferences preferences) {
             var settings = get_app ().settings;
-            var category = preferences.add_category (_("File Types"), Gtk.STOCK_FILE);
+            var category = preferences.add_category (_("File Types"), Gtk.Stock.FILE);
             preferences.add_group (null);
 
             var sizegroup = new Gtk.SizeGroup (Gtk.SizeGroupMode.HORIZONTAL);
