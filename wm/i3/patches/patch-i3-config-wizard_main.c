$NetBSD: patch-i3-config-wizard_main.c,v 1.3 2026/03/23 13:09:13 nia Exp $

Include <libgen.h> for mkdirp(3) on SunOS.

--- i3-config-wizard/main.c.orig	2026-03-23 12:17:50.971594427 +0000
+++ i3-config-wizard/main.c
@@ -36,6 +36,7 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <unistd.h>
+#include <libgen.h>
 
 #include <xcb/xcb.h>
 #include <xcb/xcb_aux.h>
