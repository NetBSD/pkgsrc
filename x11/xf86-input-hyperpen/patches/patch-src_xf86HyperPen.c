$NetBSD: patch-src_xf86HyperPen.c,v 1.1 2015/07/04 06:38:06 richard Exp $

sun specific processing obsoleted in 1.4.0
https://bugs.freedesktop.org/show_bug.cgi?id=91216

--- src/xf86HyperPen.c.orig	2011-07-05 01:34:17.000000000 +0000
+++ src/xf86HyperPen.c
@@ -845,7 +845,7 @@ xf86HypInit(InputDriverPtr      drv,
     pInfo->fd = -1;
     priv->AutoPT = 1;
 
-#if defined(sun) && !defined(i386)
+#if 0 && defined(sun) && !defined(i386)
     if (dev_name) {
         priv->hypDevice = (char *)alloc(strlen(dev_name) + 1);
         strcpy(priv->hypDevice, dev_name);
