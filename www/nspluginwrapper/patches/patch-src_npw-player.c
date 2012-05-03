$NetBSD: patch-src_npw-player.c,v 1.1 2012/05/03 06:09:55 wiz Exp $

Adapt for glib-2.32.

--- src/npw-player.c.orig	2009-01-02 08:54:10.000000000 +0000
+++ src/npw-player.c
@@ -21,8 +21,6 @@
 #include "sysdeps.h"
 #include <unistd.h>
 #include <glib.h>
-#include <glib/gstdio.h>
-#include <glib/gthread.h>
 #include <gtk/gtk.h>
 #include <gdk/gdkx.h>
 #include <gdk/gdkkeysyms.h>
