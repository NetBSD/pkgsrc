$NetBSD: patch-get__mem.c,v 1.1 2022/12/19 21:00:16 vins Exp $

Rely on procfs on NetBSD to get memory statistics.

--- get_mem.c.orig	2022-02-05 06:40:03.000000000 +0000
+++ get_mem.c
@@ -250,7 +250,7 @@ void GetMemLoadPoint(Widget w, caddr_t c
 
 
 /* ------------------------------------------------------------------ */
-#if __gnu_linux__
+#if defined(__linux__) || defined (__NetBSD__)
 #include <X11/Xos.h>
 #include <X11/Intrinsic.h>
 #include <stdio.h>
