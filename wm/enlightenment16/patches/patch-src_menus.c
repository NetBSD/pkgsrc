$NetBSD: patch-src_menus.c,v 1.1 2022/07/14 00:53:02 gutteridge Exp $

Fix potential crash if a currently displayed menu is re-requested.
Upstream commit:
http://git.enlightenment.org/e16/e16/commit/6369dfa7ddac282310fce83505212d8c9cf8f0e8

--- src/menus.c.orig	2022-06-13 06:00:07.000000000 +0000
+++ src/menus.c
@@ -1150,13 +1150,16 @@ MenusShowNamed(const char *name, const c
    if (name2)
       name = name2;
 
+   m = MenuFind(name, param);
+   if (m && m->shown)
+      return;			/* Quit if already shown */
+
    /* Hide any menus currently up */
    if (MenusActive())
       MenusHide();
 
-   m = MenuFind(name, param);
    if (!m)
-      return;
+      return;			/* Quit if menu not found */
 
    if (!m->ewin)		/* Don't show if already shown */
       MenuShow(m, 0);
