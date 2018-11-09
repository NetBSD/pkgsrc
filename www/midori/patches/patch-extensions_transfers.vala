$NetBSD: patch-extensions_transfers.vala,v 1.1 2018/11/09 09:17:07 abs Exp $

Update to build against vala-0.42.0

--- extensions/transfers.vala.orig	2015-08-30 11:56:26.000000000 +0000
+++ extensions/transfers.vala
@@ -119,7 +119,7 @@ namespace Transfers {
                 separator.draw = false;
                 separator.set_expand (true);
                 toolbar.insert (separator, -1);
-                clear = new Gtk.ToolButton.from_stock (Gtk.STOCK_CLEAR);
+                clear = new Gtk.ToolButton.from_stock (Gtk.Stock.CLEAR);
                 clear.label = _("Clear All");
                 clear.is_important = true;
                 clear.clicked.connect (clear_clicked);
@@ -213,7 +213,7 @@ namespace Transfers {
                 store.get (iter, 0, out transfer);
 
                 var menu = new Gtk.Menu ();
-                var menuitem = new Gtk.ImageMenuItem.from_stock (Gtk.STOCK_OPEN, null);
+                var menuitem = new Gtk.ImageMenuItem.from_stock (Gtk.Stock.OPEN, null);
                 menuitem.activate.connect (() => {
                     try {
                         Midori.Download.open (transfer.download, treeview);
@@ -224,7 +224,7 @@ namespace Transfers {
                 menuitem.sensitive = transfer.succeeded;
                 menu.append (menuitem);
                 menuitem = new Gtk.ImageMenuItem.with_mnemonic (_("Open Destination _Folder"));
-                menuitem.image = new Gtk.Image.from_stock (Gtk.STOCK_DIRECTORY, Gtk.IconSize.MENU);
+                menuitem.image = new Gtk.Image.from_stock (Gtk.Stock.DIRECTORY, Gtk.IconSize.MENU);
                 menuitem.activate.connect (() => {
                     var folder = GLib.File.new_for_uri (transfer.destination);
                     (Midori.Browser.get_for_widget (this).tab as Midori.Tab).open_uri (folder.get_parent ().get_uri ());
@@ -236,7 +236,7 @@ namespace Transfers {
                     get_clipboard (Gdk.SELECTION_PRIMARY).set_text (uri, -1);
                     get_clipboard (Gdk.SELECTION_CLIPBOARD).set_text (uri, -1);
                 });
-                menuitem.image = new Gtk.Image.from_stock (Gtk.STOCK_COPY, Gtk.IconSize.MENU);
+                menuitem.image = new Gtk.Image.from_stock (Gtk.Stock.COPY, Gtk.IconSize.MENU);
                 menu.append (menuitem);
                 menu.show_all ();
                 Katze.widget_popup (treeview, menu, null, Katze.MenuPos.CURSOR);
@@ -275,7 +275,7 @@ namespace Transfers {
                     Transfer found;
                     store.get (iter, 0, out found);
                     if (transfer == found) {
-                        store.remove (iter);
+                        store.remove (ref iter);
                         break;
                     }
                 } while (store.iter_next (ref iter));
@@ -394,7 +394,7 @@ namespace Transfers {
             set_style (Gtk.ToolbarStyle.BOTH_HORIZ);
             show_arrow = false;
 
-            clear = new Gtk.ToolButton.from_stock (Gtk.STOCK_CLEAR);
+            clear = new Gtk.ToolButton.from_stock (Gtk.Stock.CLEAR);
             clear.label = _("Clear All");
             clear.is_important = true;
             clear.clicked.connect (clear_clicked);
@@ -455,7 +455,7 @@ namespace Transfers {
                 if (notifications.length () == 1)
                     msg = _("The file '<b>%s</b>' has been downloaded.").printf (filename);
                 else
-                    msg = _("'<b>%s</b>' and %d other files have been downloaded.").printf (filename, notifications.length ());
+                    msg = _("'<b>%s</b>' and %u other files have been downloaded.").printf (filename, notifications.length ());
                 get_app ().send_notification (_("Transfer completed"), msg);
                 notifications = new GLib.List<string> ();
             }
@@ -514,7 +514,7 @@ namespace Transfers {
                     "%s",
                     _("Some files are being downloaded"));
                 dialog.title = _("Some files are being downloaded");
-                dialog.add_buttons (Gtk.STOCK_CANCEL, Gtk.ResponseType.CANCEL,
+                dialog.add_buttons (Gtk.Stock.CANCEL, Gtk.ResponseType.CANCEL,
                                     _("_Quit Midori"), Gtk.ResponseType.ACCEPT);
                 dialog.format_secondary_text (
                     _("The transfers will be cancelled if Midori quits."));
