$NetBSD: patch-extensions_external-download-manager.vala,v 1.1 2018/11/09 09:17:07 abs Exp $

Update to build against vala-0.42.0

--- extensions/external-download-manager.vala.orig	2015-08-30 11:56:26.000000000 +0000
+++ extensions/external-download-manager.vala
@@ -280,8 +280,8 @@ namespace EDM {
             this.vbox.pack_start (this.input, false, true, 0);
 #endif
 
-            this.add_button (Gtk.STOCK_CANCEL, Gtk.ResponseType.CANCEL);
-            this.add_button (Gtk.STOCK_APPLY, Gtk.ResponseType.APPLY);
+            this.add_button (Gtk.Stock.CANCEL, Gtk.ResponseType.CANCEL);
+            this.add_button (Gtk.Stock.APPLY, Gtk.ResponseType.APPLY);
 
             this.show_all ();
         }
