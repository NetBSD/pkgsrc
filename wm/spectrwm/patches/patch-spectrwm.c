$NetBSD: patch-spectrwm.c,v 1.1 2018/12/20 12:33:24 jaapb Exp $

NetBSD also has sys/tree.h
--- spectrwm.c.orig	2018-09-07 19:17:52.000000000 +0000
+++ spectrwm.c
@@ -42,6 +42,8 @@
 #include <sys/tree.h>
 #elif defined(__FreeBSD__)
 #include <sys/tree.h>
+#elif defined(__NetBSD__)
+#include <sys/tree.h>
 #else
 #include "tree.h"
 #endif
