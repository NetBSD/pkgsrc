$NetBSD: patch-tests_nouveau_threaded.c,v 1.3 2024/07/02 16:24:47 wiz Exp $

Use the correct form of ioctl(2) for as many systems as possible.

https://gitlab.freedesktop.org/mesa/drm/-/merge_requests/384

--- tests/nouveau/threaded.c.orig	2021-07-02 12:49:05.455772000 +0000
+++ tests/nouveau/threaded.c
@@ -36,7 +36,7 @@ static int failed;
 
 static int import_fd;
 
-#if defined(__GLIBC__) || defined(__FreeBSD__)
+#if defined(__GLIBC__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 int ioctl(int fd, unsigned long request, ...)
 #else
 int ioctl(int fd, int request, ...)
