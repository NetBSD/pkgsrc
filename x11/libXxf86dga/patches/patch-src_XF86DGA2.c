$NetBSD: patch-src_XF86DGA2.c,v 1.1 2012/06/05 22:15:03 wiz Exp $

Fix build on DragonFly i386 (and probably others).
From Gustau Pérez i Querol in
http://freebsd.1045724.n5.nabble.com/Xorg-1-12-td5642201.html

--- src/XF86DGA2.c.orig	2012-03-08 05:35:46.000000000 +0000
+++ src/XF86DGA2.c
@@ -928,7 +928,7 @@ DGAMapPhysical(
     if ((pMap->fd = open(name, O_RDWR)) < 0)
 	return False;
     pMap->virtual = mmap(NULL, size, PROT_READ | PROT_WRITE,
-			MAP_FILE | MAP_SHARED, pMap->fd, (off_t)base);
+			MAP_FILE | MAP_SHARED, pMap->fd, (off_t)(unsigned long)base);
     if (pMap->virtual == (void *)-1)
 	return False;
     mprotect(pMap->virtual, size, PROT_READ | PROT_WRITE);
