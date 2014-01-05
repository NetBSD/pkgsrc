$NetBSD: patch-src_wmtaskbar.cc,v 1.1 2014/01/05 12:33:26 ryoon Exp $

--- src/wmtaskbar.cc.orig	2013-11-17 16:54:39.000000000 +0000
+++ src/wmtaskbar.cc
@@ -80,6 +80,10 @@ static void initPixmaps() {
      * filename. This will be unified and be a forced standard in
      * icewm-2
      */
+#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
+    /* pkgsrc on *BSD: Try Beastie first */
+    startImage = subdirs->loadImage(base, "bsd-daemon.xpm");
+#else
     startImage = themedirs->loadImage(base, "start.xpm");
 #if 1
     if (startImage == null || !startImage->valid())
@@ -91,6 +95,7 @@ static void initPixmaps() {
     if (startImage == null || !startImage->valid())
         startImage = subdirs->loadImage(base, "start.xpm");
 #endif
+#endif
 
     windowsImage = subdirs->loadImage(base, "windows.xpm");
     showDesktopImage = subdirs->loadImage(base, "desktop.xpm");
