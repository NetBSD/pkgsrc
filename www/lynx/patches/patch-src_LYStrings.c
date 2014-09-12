$NetBSD: patch-src_LYStrings.c,v 1.1 2014/09/12 21:29:22 wiz Exp $

Fix build with ncursesw.

--- src/LYStrings.c.orig	2013-11-29 00:52:56.000000000 +0000
+++ src/LYStrings.c
@@ -40,6 +40,10 @@
 #include <LYrcFile.h>
 #endif
 
+#ifdef NCURSES
+#include <ncurses/term.h>
+#endif
+
 #include <LYShowInfo.h>
 #include <LYLeaks.h>
 
