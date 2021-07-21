$NetBSD: patch-hw_xfree86_os-support_bsd_alpha__video.c,v 1.1 2021/07/21 21:50:29 tnn Exp $

Fix build on NetBSD/alpha. From xsrc.

--- hw/xfree86/os-support/bsd/alpha_video.c.orig	2021-07-08 19:22:18.000000000 +0000
+++ hw/xfree86/os-support/bsd/alpha_video.c
@@ -34,6 +34,9 @@
 #include <sys/param.h>
 #ifndef __NetBSD__
 #include <sys/sysctl.h>
+#else
+#include <machine/sysarch.h>
+#include <machine/pio.h>
 #endif
 
 #include "xf86_OSlib.h"
