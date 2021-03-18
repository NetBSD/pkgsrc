$NetBSD: patch-src_lxhotkey.c,v 1.1 2021/03/18 00:21:26 gutteridge Exp $

Needs locale.h.

--- src/lxhotkey.c.orig	2021-01-30 21:22:44.000000000 +0000
+++ src/lxhotkey.c
@@ -29,6 +29,7 @@
 #include <X11/Xlib.h>
 #include <X11/Xatom.h>
 
+#include <locale.h>
 #include <stdlib.h>
 
 #ifdef HAVE_LIBUNISTRING
