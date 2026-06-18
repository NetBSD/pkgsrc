$NetBSD: patch-wmclockmon-cal_mainwindow.c,v 1.1 2026/06/18 19:50:48 nia Exp $

Include the correct header for bzero(3).

--- wmclockmon-cal/mainwindow.c.orig	2026-06-18 19:48:05.201514487 +0000
+++ wmclockmon-cal/mainwindow.c
@@ -9,6 +9,7 @@
 #include <dirent.h>
 #include <gtk/gtk.h>
 #include <string.h>
+#include <strings.h>
 #include <unistd.h>
 #include "../config.h"
 #include "defines.h"
