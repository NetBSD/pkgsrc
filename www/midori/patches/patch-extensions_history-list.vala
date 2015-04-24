$NetBSD: patch-extensions_history-list.vala,v 1.1 2015/04/24 11:23:05 joerg Exp $

--- extensions/history-list.vala.orig	2015-04-23 18:29:27.000000000 +0000
+++ extensions/history-list.vala
@@ -319,7 +319,7 @@ namespace HistoryList {
         }
 
         private void create_widgets () {
-            ListStore model;
+            Gtk.ListStore model;
             TreeIter iter;
             TreeIter? active_iter = null;
 
@@ -331,7 +331,7 @@ namespace HistoryList {
 
             var tab_closing_behavior = this.hl_manager.get_integer ("TabClosingBehavior");
 
-            model = new ListStore (2, typeof (string), typeof (int));
+            model = new Gtk.ListStore (2, typeof (string), typeof (int));
 
             model.append (out iter);
             model.set (iter, TabClosingBehaviorModel.TEXT, _("Do nothing"),
