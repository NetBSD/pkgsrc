$NetBSD: patch-katze_midori-paths.vala,v 1.1 2018/11/09 09:17:07 abs Exp $

Update to build against vala-0.42.0

--- katze/midori-paths.vala.orig	2015-08-30 11:56:26.000000000 +0000
+++ katze/midori-paths.vala
@@ -485,7 +485,7 @@ namespace Midori {
                 return pixbuf;
 #endif
             if (widget != null)
-                return widget.render_icon (Gtk.STOCK_FILE, Gtk.IconSize.MENU, null);
+                return widget.render_icon (Gtk.Stock.FILE, Gtk.IconSize.MENU, null);
             return null;
         }
     }
