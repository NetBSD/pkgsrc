$NetBSD: patch-src_emuwheel.c,v 1.1 2015/12/18 11:19:12 taca Exp $

* Fix build problem NetBSD 7.0_STABLE.

--- src/emuwheel.c.orig	2012-07-08 13:51:11.000000000 +0000
+++ src/emuwheel.c
@@ -36,6 +36,8 @@
 #include "config.h"
 #endif
 
+#include <sys/time.h>
+
 #include <xorg-server.h>
 #include <X11/Xatom.h>
 #include <xf86.h>
