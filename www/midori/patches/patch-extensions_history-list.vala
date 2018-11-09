$NetBSD: patch-extensions_history-list.vala,v 1.3 2018/11/09 09:17:07 abs Exp $

Update to build against vala-0.42.0

--- extensions/history-list.vala.orig	2015-08-30 11:56:26.000000000 +0000
+++ extensions/history-list.vala
@@ -223,7 +223,7 @@ namespace HistoryList {
                     FixMe: the retrun value of `Gtk.ListStore.remove` should be checked
                     Note:  in some cases the return value of `Gtk.ListStore.remove` is wrong
                 */
-                model.remove (iter);
+                model.remove (ref iter);
                 this.browser.close_tab (view);
                 if (length > 2)
                     this.resize_treeview ();
@@ -365,8 +365,8 @@ namespace HistoryList {
             this.vbox.pack_start (table, false, true, 0);
 #endif
 
-            this.add_button (Gtk.STOCK_CANCEL, Gtk.ResponseType.CANCEL);
-            this.add_button (Gtk.STOCK_APPLY, Gtk.ResponseType.APPLY);
+            this.add_button (Gtk.Stock.CANCEL, Gtk.ResponseType.CANCEL);
+            this.add_button (Gtk.Stock.APPLY, Gtk.ResponseType.APPLY);
 
             this.show_all ();
         }
