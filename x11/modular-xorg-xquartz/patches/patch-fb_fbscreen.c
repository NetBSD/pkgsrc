$NetBSD: patch-fb_fbscreen.c,v 1.1 2015/10/01 12:55:09 tnn Exp $

http://cgit.freedesktop.org/~jeremyhu/xserver/log/?h=server-1.17-apple

--- fb/fbscreen.c.orig	2014-10-23 22:11:20.000000000 +0000
+++ fb/fbscreen.c
@@ -32,7 +32,6 @@ fbCloseScreen(ScreenPtr pScreen)
     int d;
     DepthPtr depths = pScreen->allowedDepths;
 
-    fbDestroyGlyphCache();
     for (d = 0; d < pScreen->numDepths; d++)
         free(depths[d].vids);
     free(depths);
