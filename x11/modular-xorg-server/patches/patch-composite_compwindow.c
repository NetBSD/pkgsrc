$NetBSD: patch-composite_compwindow.c,v 1.1 2023/03/29 12:46:37 wiz Exp $

Fix for ZDI-CAN-19866/CVE-2023-1393
https://gitlab.freedesktop.org/xorg/xserver/-/commit/26ef545b3

--- composite/compwindow.c.orig	2023-02-07 01:16:51.000000000 +0000
+++ composite/compwindow.c
@@ -620,6 +620,11 @@ compDestroyWindow(WindowPtr pWin)
     ret = (*pScreen->DestroyWindow) (pWin);
     cs->DestroyWindow = pScreen->DestroyWindow;
     pScreen->DestroyWindow = compDestroyWindow;
+
+    /* Did we just destroy the overlay window? */
+    if (pWin == cs->pOverlayWin)
+        cs->pOverlayWin = NULL;
+
 /*    compCheckTree (pWin->drawable.pScreen); can't check -- tree isn't good*/
     return ret;
 }
