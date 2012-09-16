$NetBSD: patch-src_i830.h,v 1.1 2012/09/16 02:19:20 khorben Exp $

Make xf86-video-intel driver work on Atom N455 + GMA3150 graphics chipset, much like done for xsrc already:
http://mail-index.netbsd.org/source-changes/2012/06/08/msg034860.html

--- src/i830.h.orig	2009-05-13 00:12:11.000000000 +0000
+++ src/i830.h
@@ -972,6 +972,8 @@ static inline int i830_fb_compression_su
 	return FALSE;
     if (IS_I810(pI830) || IS_I815(pI830) || IS_I830(pI830))
 	return FALSE;
+    if (IS_IGD(pI830))
+	return FALSE;
     /* fbc depends on tiled surface. And we don't support tiled
      * front buffer with XAA now.
      */
