$NetBSD: patch-src_wmconfig.c,v 1.1 2013/05/22 18:01:25 tron Exp $

Fix build with WindowMaker 0.95.4 and change hard coded path name.

--- src/wmconfig.c.orig	2004-12-05 03:19:23.000000000 +0000
+++ src/wmconfig.c	2013-05-22 18:52:57.000000000 +0100
@@ -216,7 +216,7 @@
 	 /*
 	  *  Generate backup file "'path'.bak"
 	  */
-	 if (WMWritePropListToFile (orig_rootmenu, new, YES))
+	 if (WMWritePropListToFile (orig_rootmenu, new))
 	    message (_("Backupfile `%s' generated."), new);
 	 else
 	    error (_("Can't write backupfile `%s'."), new);
@@ -280,7 +280,7 @@
    if (!windowmaker)
    {
       windowmaker = global_windowmaker;
-      if (WMWritePropListToFile (windowmaker, orig_wmaker_fname, YES))
+      if (WMWritePropListToFile (windowmaker, orig_wmaker_fname))
 	 warning (_("New WindowMaker configuration file `%s' created."),
 		  orig_wmaker_fname);
       else
@@ -294,7 +294,7 @@
       /*
        *  Generate backup file "'path'.bak"
        */
-      if (WMWritePropListToFile (windowmaker, new, YES))
+      if (WMWritePropListToFile (windowmaker, new))
 	 message (_("Backupfile `%s' generated."), new);
       else
 	 error (_("Can't write backupfile `%s'."), new);
