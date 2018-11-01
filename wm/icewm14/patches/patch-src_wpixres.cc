$NetBSD: patch-src_wpixres.cc,v 1.1 2018/11/01 09:25:29 bsiegert Exp $

Use The BSD Daemon instead of Tux on *BSD.

--- src/wpixres.cc.orig	2017-07-30 08:53:35.000000000 +0000
+++ src/wpixres.cc
@@ -294,7 +294,11 @@ static const PixmapResource taskbar2PixR
 #endif
 
     PixmapResource(taskbarStartImage, "start.xpm", "icewm.xpm"),
+#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
+    PixmapResource(taskbarLinuxImage, "bsd-daemon.xpm"),
+#else
     PixmapResource(taskbarLinuxImage, "linux.xpm"),     // deprecated
+#endif
     PixmapResource(taskbarWindowsImage, "windows.xpm"),
     PixmapResource(taskbarShowDesktopImage, "desktop.xpm"),
     PixmapResource(taskbarCollapseImage, "collapse.xpm"),
