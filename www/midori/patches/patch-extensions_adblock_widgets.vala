$NetBSD: patch-extensions_adblock_widgets.vala,v 1.1 2018/11/09 09:17:07 abs Exp $

Update to build against vala-0.42.0

--- extensions/adblock/widgets.vala.orig	2015-08-30 11:56:26.000000000 +0000
+++ extensions/adblock/widgets.vala
@@ -27,7 +27,7 @@ namespace Adblock {
             this.debug_element_toggled = false;
 
             var item = new Midori.ContextAction ("Preferences",
-                _("Preferences"), null, Gtk.STOCK_PREFERENCES);
+                _("Preferences"), null, Gtk.Stock.PREFERENCES);
             item.activate.connect (() => {
                 manager.add_subscription (null);
             });
@@ -99,12 +99,12 @@ namespace Adblock {
                 Gtk.DialogFlags.NO_SEPARATOR |
 #endif
                 Gtk.DialogFlags.DESTROY_WITH_PARENT,
-                Gtk.STOCK_HELP, Gtk.ResponseType.HELP,
-                Gtk.STOCK_CLOSE, Gtk.ResponseType.CLOSE);
+                Gtk.Stock.HELP, Gtk.ResponseType.HELP,
+                Gtk.Stock.CLOSE, Gtk.ResponseType.CLOSE);
 #if HAVE_GTK3
             dialog.get_widget_for_response (Gtk.ResponseType.HELP).get_style_context ().add_class ("help_button");
 #endif
-            dialog.set_icon_name (Gtk.STOCK_PROPERTIES);
+            dialog.set_icon_name (Gtk.Stock.PROPERTIES);
             dialog.set_response_sensitive (Gtk.ResponseType.HELP, false);
 
             var hbox = new Gtk.HBox (false, 0);
@@ -211,7 +211,7 @@ namespace Adblock {
             Subscription sub;
             liststore.get (iter, 0, out sub);
 
-            renderer.set ("stock-id", sub.mutable ? Gtk.STOCK_DELETE : null,
+            renderer.set ("stock-id", sub.mutable ? Gtk.Stock.DELETE : null,
                           "stock-size", Gtk.IconSize.MENU);
         }
 
@@ -227,7 +227,7 @@ namespace Adblock {
                             liststore.get (iter, 0, out sub);
                             if (sub.mutable) {
                                 config.remove (sub);
-                                liststore.remove (iter);
+                                liststore.remove (ref iter);
                                 return true;
                             }
                         }
@@ -258,9 +258,9 @@ namespace Adblock {
                 Gtk.DialogFlags.NO_SEPARATOR |
 #endif
                 Gtk.DialogFlags.DESTROY_WITH_PARENT,
-                Gtk.STOCK_CANCEL, Gtk.ResponseType.CANCEL,
-                Gtk.STOCK_ADD, Gtk.ResponseType.ACCEPT);
-            dialog.set_icon_name (Gtk.STOCK_ADD);
+                Gtk.Stock.CANCEL, Gtk.ResponseType.CANCEL,
+                Gtk.Stock.ADD, Gtk.ResponseType.ACCEPT);
+            dialog.set_icon_name (Gtk.Stock.ADD);
             dialog.resizable = false;
 
             var hbox = new Gtk.HBox (false, 8);
