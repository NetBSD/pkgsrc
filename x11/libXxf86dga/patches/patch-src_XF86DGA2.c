$NetBSD: patch-src_XF86DGA2.c,v 1.2 2012/06/12 22:31:11 wiz Exp $

From upstream.
First chunk:
http://cgit.freedesktop.org/xorg/lib/libXxf86dga/commit/?id=d4f89f7f42484963575b4c7d2fa694051e111e76
Second chunk:
http://cgit.freedesktop.org/xorg/lib/libXxf86dga/commit/?id=56b5a5887349e9d0e1d28da157fe6441ca691f56

--- src/XF86DGA2.c.orig	2012-03-08 05:35:46.000000000 +0000
+++ src/XF86DGA2.c
@@ -21,6 +21,7 @@ Copyright (c) 1995,1996  The XFree86 Pro
 #include <X11/extensions/extutil.h>
 #include <stdio.h>
 
+#include <stdint.h>
 
 /* If you change this, change the Bases[] array below as well */
 #define MAX_HEADS 16
@@ -928,7 +929,7 @@ DGAMapPhysical(
     if ((pMap->fd = open(name, O_RDWR)) < 0)
 	return False;
     pMap->virtual = mmap(NULL, size, PROT_READ | PROT_WRITE,
-			MAP_FILE | MAP_SHARED, pMap->fd, (off_t)base);
+			MAP_FILE | MAP_SHARED, pMap->fd, (off_t)(uintptr_t)base);
     if (pMap->virtual == (void *)-1)
 	return False;
     mprotect(pMap->virtual, size, PROT_READ | PROT_WRITE);
