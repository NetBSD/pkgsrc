$NetBSD: patch-src_rootmenu.c,v 1.1 2013/05/22 18:01:25 tron Exp $

Fix build with WindowMaker 0.95.4 and change hard coded path name.

--- src/rootmenu.c.orig	2005-02-26 14:31:26.000000000 +0000
+++ src/rootmenu.c	2013-05-22 18:39:04.000000000 +0100
@@ -365,7 +365,7 @@
 		       node_freeitem, NULL);
       g_node_destroy (node);
 
-      if (WMWritePropListToFile (menu, filename, YES))
+      if (WMWritePropListToFile (menu, filename))
       {
 	 menu_changed = NO;
 	 message (_("Window Maker root menu file '%s' saved."), filename);
@@ -477,7 +477,7 @@
 
       if (!file)
       {
-	 file = fopen ("/etc/X11/WindowMaker/menu.hook", "r");
+	 file = fopen (WMAKERDIR "/menu.hook", "r");
 	 if (file)
 	 {
 	    debian_menu = YES;
