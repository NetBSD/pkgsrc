$NetBSD: patch-menu.c,v 1.1 2026/06/20 10:40:33 nia Exp $

Fix implicit declaration of exit(3).

--- menu.c.orig	2026-06-20 10:38:00.243500956 +0000
+++ menu.c
@@ -1,5 +1,6 @@
 /* Copyright (c) 1994 David Hogan, 2000 Benjamin Drieu, see README for licence details */
 #include <stdio.h>
+#include <stdlib.h>
 #include <unistd.h>
 #include <unistd.h>
 #include <sys/types.h>
