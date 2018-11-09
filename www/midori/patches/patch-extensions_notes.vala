$NetBSD: patch-extensions_notes.vala,v 1.1 2018/11/09 09:17:07 abs Exp $

Update to build against vala-0.42.0

--- extensions/notes.vala.orig	2015-08-30 11:56:26.000000000 +0000
+++ extensions/notes.vala
@@ -116,7 +116,7 @@ namespace ClipNotes {
                     if (current_note == note) {
                         current_note = null;
                     }
-                    notes_list_store.remove (iter);
+                    notes_list_store.remove (ref iter);
                     break;
                 }
             } while (notes_list_store.iter_next (ref iter));
@@ -131,7 +131,7 @@ namespace ClipNotes {
         Gtk.TextView note_text_view = new Gtk.TextView ();
 
         public unowned string get_stock_id () {
-            return Gtk.STOCK_EDIT;
+            return Gtk.Stock.EDIT;
         }
 
         public unowned string get_label () {
@@ -141,7 +141,7 @@ namespace ClipNotes {
         public Gtk.Widget get_toolbar () {
             if (toolbar == null) {
                 toolbar = new Gtk.Toolbar ();
-                var new_note_button = new Gtk.ToolButton.from_stock (Gtk.STOCK_EDIT);
+                var new_note_button = new Gtk.ToolButton.from_stock (Gtk.Stock.EDIT);
                 new_note_button.label = _("New Note");
                 new_note_button.tooltip_text = _("Creates a new empty note, unrelated to opened pages");
                 new_note_button.use_underline  = true;
@@ -337,7 +337,7 @@ namespace ClipNotes {
                 var menu = new Gtk.Menu ();
 
                 var menuitem = new Gtk.ImageMenuItem.with_label (_("Rename note"));
-                var image = new Gtk.Image.from_stock (Gtk.STOCK_EDIT, Gtk.IconSize.MENU);
+                var image = new Gtk.Image.from_stock (Gtk.Stock.EDIT, Gtk.IconSize.MENU);
                 menuitem.always_show_image = true;
                 menuitem.set_image (image);
                 menuitem.activate.connect (() => {
@@ -348,7 +348,7 @@ namespace ClipNotes {
 
 
                 menuitem = new Gtk.ImageMenuItem.with_label (_("Copy note to clipboard"));
-                image = new Gtk.Image.from_stock (Gtk.STOCK_COPY, Gtk.IconSize.MENU);
+                image = new Gtk.Image.from_stock (Gtk.Stock.COPY, Gtk.IconSize.MENU);
                 menuitem.always_show_image = true;
                 menuitem.set_image (image);
                 menuitem.activate.connect (() => {
@@ -358,7 +358,7 @@ namespace ClipNotes {
 
 
                 menuitem = new Gtk.ImageMenuItem.with_label (_("Remove note"));
-                image = new Gtk.Image.from_stock (Gtk.STOCK_DELETE, Gtk.IconSize.MENU);
+                image = new Gtk.Image.from_stock (Gtk.Stock.DELETE, Gtk.IconSize.MENU);
                 menuitem.always_show_image = true;
                 menuitem.set_image (image);
                 menuitem.activate.connect (() => {
