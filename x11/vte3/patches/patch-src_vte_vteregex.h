$NetBSD: patch-src_vte_vteregex.h,v 1.1 2024/10/04 00:25:05 gutteridge Exp $

Fix builds with GCC 14 (undeclared types errors).
https://gitlab.gnome.org/GNOME/vte/-/commit/0d393b6cd6a24f53eaefa16764b9453a1483acf5

--- src/vte/vteregex.h.orig	2024-06-10 19:42:45.000000000 +0000
+++ src/vte/vteregex.h
@@ -23,6 +23,7 @@
 
 #include <glib.h>
 #include <glib-object.h>
+#include <stdint.h>
 
 #include "vtemacros.h"
 
