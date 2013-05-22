$NetBSD: patch-src_themebrowser.c,v 1.1 2013/05/22 18:01:25 tron Exp $

Fix build with WindowMaker 0.95.4 and change hard coded path name.

--- src/themebrowser.c.orig	2005-02-25 23:37:44.000000000 +0000
+++ src/themebrowser.c	2013-05-22 18:55:24.000000000 +0100
@@ -2705,7 +2705,7 @@
 	 oldfiles = g_list_remove (oldfiles, tmp);
 	 Free (tmp);
       }
-      if (!WMWritePropListToFile (theme, stylename, YES))
+      if (!WMWritePropListToFile (theme, stylename))
       {
 	 dialog_popup (DIALOG_ERROR, NULL, NULL,
 		       _("Can't save theme file\n`%s'\n"
