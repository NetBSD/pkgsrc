$NetBSD: patch-add__window.c,v 1.1 2026/06/18 19:16:59 nia Exp $

Avoid implicit int, it's forbidden by newer GCC versions.

--- add_window.c.orig	2026-06-18 19:05:04.920108763 +0000
+++ add_window.c
@@ -457,9 +457,9 @@ AddWindow(Window w, int iconm, IconMgr * iconp)
   if (Scr->StormPositioning && HandlingEvents == TRUE &&
       !(tmp_win->hints.flags & USPosition) && (tmp_win->group != tmp_win->w))
   {
-    static lastwingroup = 0;
-    static lastwin = 0;
-    static lasttime = 0;
+    static int lastwingroup = 0;
+    static int lastwin = 0;
+    static int lasttime = 0;
     int curtime = time(NULL);
     Window junk;
 
