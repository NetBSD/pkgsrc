$NetBSD: patch-tests_nouveau_threaded.c,v 1.1 2022/03/13 15:20:01 tnn Exp $

--- tests/nouveau/threaded.c.orig	2021-07-02 12:49:05.455772000 +0000
+++ tests/nouveau/threaded.c
@@ -36,7 +36,7 @@ static int failed;
 
 static int import_fd;
 
-#if defined(__GLIBC__) || defined(__FreeBSD__)
+#if defined(__GLIBC__) || defined(__FreeBSD__) || defined(__NetBSD__)
 int ioctl(int fd, unsigned long request, ...)
 #else
 int ioctl(int fd, int request, ...)
