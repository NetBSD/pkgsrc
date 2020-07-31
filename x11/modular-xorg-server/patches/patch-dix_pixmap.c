$NetBSD: patch-dix_pixmap.c,v 1.1 2020/07/31 16:50:57 maya Exp $

From aac28e162e5108510065ad4c323affd6deffd816 Mon Sep 17 00:00:00 2001
From: Matthieu Herrb <matthieu@herrb.eu>
Date: Sat, 25 Jul 2020 19:33:50 +0200
Subject: [PATCH] fix for ZDI-11426

Avoid leaking un-initalized memory to clients by zeroing the
whole pixmap on initial allocation.

This vulnerability was discovered by:
Jan-Niklas Sohn working with Trend Micro Zero Day Initiative

Signed-off-by: Matthieu Herrb <matthieu@herrb.eu>
Reviewed-by: Alan Coopersmith <alan.coopersmith@oracle.com>

--- dix/pixmap.c.orig	2020-03-29 20:21:15.000000000 +0000
+++ dix/pixmap.c
@@ -117,7 +117,7 @@ AllocatePixmap(ScreenPtr pScreen, int pi
     if (pScreen->totalPixmapSize > ((size_t) - 1) - pixDataSize)
         return NullPixmap;
 
-    pPixmap = malloc(pScreen->totalPixmapSize + pixDataSize);
+    pPixmap = calloc(1, pScreen->totalPixmapSize + pixDataSize);
     if (!pPixmap)
         return NullPixmap;
 
